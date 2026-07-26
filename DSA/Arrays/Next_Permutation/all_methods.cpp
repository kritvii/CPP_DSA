#include <iostream>
#include <vector>
#include <algorithm>  // for next_permutation(), reverse(), swap()
using namespace std;

// ════════════════════════════════════════════════════════════════
// LC 31 - Next Permutation
// Given an array, rearrange it into the lexicographically next
// greater permutation. If not possible, return the smallest.
// ════════════════════════════════════════════════════════════════


// ── APPROACH 1: Brute Force ──────────────────────────────────────
// Time : O(n! × n)  |  Space : O(n!)
// generate ALL permutations, sort them, find current, return next
// TLE on large inputs — only for understanding the problem

void bruteForce(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> perms;

    // sort first to start from smallest permutation
    sort(nums.begin(), nums.end());

    // generate all permutations
    do {
        perms.push_back(nums);
    } while(next_permutation(nums.begin(), nums.end()));

    // find current permutation and return next
    for(int i = 0; i < perms.size(); i++) {
        if(perms[i] == nums) {
            if(i == (int)perms.size() - 1)
                nums = perms[0];     // last permutation → return first
            else
                nums = perms[i+1];  // return next permutation
            return;
        }
    }
}

// DRY RUN: [1, 2, 3]
// all perms = [1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]
// current = [1,2,3] at index 0 → return perms[1] = [1,3,2] ✓

// WHY O(n! × n)?
// n! permutations × n elements each = O(n! × n)
// for n=10 → 10! = 3,628,800 permutations → way too slow


// ── APPROACH 2: One Line (STL) ───────────────────────────────────
// Time : O(n)  |  Space : O(1)
// uses C++ built-in next_permutation from <algorithm>
// accepted on LC but NOT allowed in interviews
// internally uses the same 3-step optimal approach

void oneLineSolution(vector<int>& nums) {
    next_permutation(nums.begin(), nums.end());
}


// ── APPROACH 3: Optimal (3-step) ─────────────────────────────────
// Time : O(n)  |  Space : O(1)
// step 1: find pivot → first element smaller than right neighbour
// step 2: find rightmost element > pivot → swap
// step 3: reverse suffix after pivot → gives smallest arrangement

// WHY REVERSE AFTER SWAP?
// after swap, suffix is still descending
// reversing gives smallest arrangement → O(n) vs sort O(n log n)

void optimal(vector<int>& nums) {
    int n     = nums.size();
    int pivot = -1;

    // step 1: find pivot — scan right to left
    // start at n-2 → nums[i+1] when i=n-1 would be out of bounds
    for(int i = n-2; i >= 0; i--) {
        if(nums[i] < nums[i+1]) {
            pivot = i;
            break;
        }
    }

    // no pivot → array fully descending → already largest permutation
    // [5,4,3,2,1]: i=3→2<1?NO, i=2→3<2?NO, i=1→4<3?NO, i=0→5<4?NO
    // pivot stays -1 → reverse entire array → smallest permutation
    if(pivot == -1) {
        reverse(nums.begin(), nums.end());
        return;  // exit early — no more steps needed
    }

    // step 2: find rightmost element > pivot → swap
    for(int i = n-1; i > pivot; i--) {
        if(nums[i] > nums[pivot]) {
            swap(nums[pivot], nums[i]);
            break;  // first from right is correct → stop immediately
        }
    }

    // step 3: reverse suffix after pivot
    // nums.begin()+pivot+1 → one position after pivot
    reverse(nums.begin() + pivot + 1, nums.end());
}

// DRY RUN 1: [1, 2, 5, 4, 3]
// step 1: i=1 → 2<5 → pivot=1
// step 2: i=4 → 3>2 → swap(1,4) → [1,3,5,4,2], break
// step 3: reverse from index 2 → [5,4,2] → [2,4,5]
// final: [1,3,2,4,5] ✓

// DRY RUN 2: [5, 4, 3, 2, 1] (pivot==-1 case)
// step 1: no element found where nums[i]<nums[i+1] → pivot=-1
// reverse entire array → [1,2,3,4,5] ✓

// DRY RUN 3: [1, 2, 3]
// step 1: i=1 → 2<3 → pivot=1
// step 2: i=2 → 3>2 → swap → [1,3,2], break
// step 3: reverse from index 2 → [2] → no change
// final: [1,3,2] ✓


// ── COMPARISON ───────────────────────────────────────────────────
// Approach 1 — Brute Force  : O(n!×n) time | O(n!) space → TLE
// Approach 2 — One Line STL : O(n)    time | O(1)  space → no interviews
// Approach 3 — Optimal      : O(n)    time | O(1)  space → best ✓


// ── TRAPS ────────────────────────────────────────────────────────
// ❌ loop starts at n-1 → nums[i+1] out of bounds
// ✅ loop starts at n-2
// ❌ no return after reverse in pivot==-1 → runs steps 2 and 3 wrongly
// ✅ return immediately after reverse
// ❌ no break in step 2 → keeps swapping wrong elements
// ✅ break after first swap from right
// ❌ using sort() for step 3 → O(n log n)
// ✅ reverse() is enough → O(n) since suffix already descending


int main() {

    // test case 1 — expected: [1, 3, 2]
    vector<int> nums1 = {1, 2, 3};
    optimal(nums1);
    cout << "Test 1: ";
    for(int x : nums1) cout << x << " ";
    cout << endl;

    // test case 2 — expected: [1, 2, 3, 4, 5] (fully descending → pivot==-1)
    vector<int> nums2 = {5, 4, 3, 2, 1};
    optimal(nums2);
    cout << "Test 2: ";
    for(int x : nums2) cout << x << " ";
    cout << endl;

    // test case 3 — expected: [1, 3, 2, 4, 5]
    vector<int> nums3 = {1, 2, 5, 4, 3};
    optimal(nums3);
    cout << "Test 3: ";
    for(int x : nums3) cout << x << " ";
    cout << endl;

    // test case 4 — single element — expected: [1]
    vector<int> nums4 = {1};
    optimal(nums4);
    cout << "Test 4: ";
    for(int x : nums4) cout << x << " ";
    cout << endl;

    return 0;
}