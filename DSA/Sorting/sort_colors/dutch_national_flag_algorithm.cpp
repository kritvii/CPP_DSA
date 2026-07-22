#include <iostream>
#include <vector>
#include <algorithm>  // for swap()
using namespace std;

// SORT COLORS - Dutch National Flag Algorithm
// 3 pointers: low, mid, high
// low  → everything before low is 0
// mid  → current element being examined
// high → everything after high is 2

void sortColors(vector<int>& nums) {
    int n    = nums.size();
    int low  = 0;
    int mid  = 0;
    int high = n - 1;

    while(mid <= high) {

        if(nums[mid] == 0) {
            // swap 0 to the left section
            // both low and mid move forward
            swap(nums[mid], nums[low]);
            low++;
            mid++;
        }
        else if(nums[mid] == 1) {
            // 1 is already in correct middle section
            // just move mid forward
            mid++;
        }
        else {
            // swap 2 to the right section
            // high moves back but mid stays —
            // swapped element from high is unknown, needs to be checked again
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main() {

    // test case 1 — expected: [0, 0, 1, 1, 2, 2]
    vector<int> nums1 = {2, 0, 2, 1, 1, 0};
    sortColors(nums1);
    cout << "Test 1: ";
    for(int x : nums1) cout << x << " ";
    cout << endl;

    // test case 2 — expected: [0, 1, 2]
    vector<int> nums2 = {2, 0, 1};
    sortColors(nums2);
    cout << "Test 2: ";
    for(int x : nums2) cout << x << " ";
    cout << endl;

    // test case 3 — all same — expected: [0, 0, 0]
    vector<int> nums3 = {0, 0, 0};
    sortColors(nums3);
    cout << "Test 3: ";
    for(int x : nums3) cout << x << " ";
    cout << endl;

    // test case 4 — already sorted — expected: [0, 1, 2]
    vector<int> nums4 = {0, 1, 2};
    sortColors(nums4);
    cout << "Test 4: ";
    for(int x : nums4) cout << x << " ";
    cout << endl;

    return 0;
}

// DRY RUN: [2, 0, 2, 1, 1, 0]
// low=0, mid=0, high=5
// mid=0: nums[0]=2 → swap(0,5) → [0,0,2,1,1,2], high=4
// mid=0: nums[0]=0 → swap(0,0) → [0,0,2,1,1,2], low=1, mid=1
// mid=1: nums[1]=0 → swap(1,1) → [0,0,2,1,1,2], low=2, mid=2
// mid=2: nums[2]=2 → swap(2,4) → [0,0,1,1,2,2], high=3
// mid=2: nums[2]=1 → mid=3
// mid=3: nums[3]=1 → mid=4
// mid=4 > high=3 → loop ends
// result: [0, 0, 1, 1, 2, 2] ✓

// COMPLEXITY:
// Time  → O(n) — single pass through array
// Space → O(1) — in place, no extra array

// TRAPS:
// ❌ elif → Python syntax, doesn't exist in C++
// ✅ else if → correct C++ syntax
// ❌ moving mid when swapping with high → skips unchecked element
// ✅ only move high--, mid stays to recheck swapped element