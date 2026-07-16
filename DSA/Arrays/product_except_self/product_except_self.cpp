#include <iostream>
#include <vector>
using namespace std;

// ════════════════════════════════════════════════════════════════
// LC 238 - Product of Array Except Self
// Given an array nums, return array ans where ans[i] = product
// of all elements except nums[i]. No division. O(n) required.
// ════════════════════════════════════════════════════════════════


// ── APPROACH 1: Brute Force ──────────────────────────────────────
// Time : O(n²)  |  Space : O(n)
// for every index i, multiply all elements except nums[i]
// correct but TLE on large inputs

vector<int> bruteForce(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans;

    for(int i = 0; i < n; i++) {
        int prod = 1;

        for(int j = 0; j < n; j++) {
            if(i != j)          // skip current index
                prod *= nums[j];
        }

        ans.push_back(prod);
    }

    return ans;
}

// DRY RUN: [1, 2, 3, 4]
// i=0 → skip j=0 → prod = 2×3×4 = 24
// i=1 → skip j=1 → prod = 1×3×4 = 12
// i=2 → skip j=2 → prod = 1×2×4 = 8
// i=3 → skip j=3 → prod = 1×2×3 = 6
// ans = [24, 12, 8, 6] ✓


// ── APPROACH 2: Prefix + Suffix Arrays ───────────────────────────
// Time : O(n)  |  Space : O(n)
// prefix[i] = product of everything LEFT of i
// suffix[i] = product of everything RIGHT of i
// ans[i]    = prefix[i] × suffix[i]

vector<int> prefixSuffixArrays(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);
    vector<int> prefix(n);
    vector<int> suffix(n);

    // build prefix left to right
    // nothing to the left of index 0 → init to 1
    prefix[0] = 1;
    for(int i = 1; i < n; i++){
        prefix[i] = prefix[i-1] * nums[i-1];
    }
    // nums   = [1,  2,  3,  4]
    // prefix = [1,  1,  2,  6]

    // build suffix right to left
    // nothing to the right of last index → init to 1
    suffix[n-1] = 1;
    for(int i = n-2; i >= 0; i--){
        suffix[i] = suffix[i+1] * nums[i+1];
    }
    // nums   = [1,  2,  3,  4]
    // suffix = [24, 12, 4,  1]

    // combine — ans[i] = left product × right product
    for(int i = 0; i < n; i++){
        ans[i] = prefix[i] * suffix[i];
    }
    // ans = [24, 12, 8, 6] ✓

    return ans;
}

// DRY RUN: [1, 2, 3, 4]
// prefix = [1,  1,  2,  6]
// suffix = [24, 12, 4,  1]
// ans[0] = 1×24 = 24
// ans[1] = 1×12 = 12
// ans[2] = 2×4  = 8
// ans[3] = 6×1  = 6
// ans = [24, 12, 8, 6] ✓


// ── APPROACH 3: Prefix + Running Suffix Variable ─────────────────
// Time : O(n)  |  Space : O(1) extra  ← best version
// same idea as approach 2 but no suffix array
// use a single variable to carry running right product

vector<int> optimized(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 1);  // init to 1 — holds prefix first, then final ans

    // pass 1: fill ans with prefix products (left to right)
    // ans[0] stays 1 — nothing to the left of index 0
    for(int i = 1; i < n; i++){
        ans[i] = ans[i-1] * nums[i-1];
    }
    // ans = [1, 1, 2, 6]

    // pass 2: multiply running suffix into ans (right to left)
    // suffix = running product of everything to the RIGHT
    // update suffix first → then multiply into ans[i]
    int suffix = 1;
    for(int i = n-2; i >= 0; i--){
        suffix *= nums[i+1];  // bring in element just to the right
        ans[i] *= suffix;     // ans[i] = prefix × suffix → final answer
    }
    // ans[n-1] untouched → stays at prefix value (correct)
    // ans = [24, 12, 8, 6] ✓

    return ans;
}

// DRY RUN: [1, 2, 3, 4]
// after pass 1: ans = [1,  1,  2,  6]
// i=2: suffix=1×4=4,   ans[2]=2×4=8
// i=1: suffix=4×3=12,  ans[1]=1×12=12
// i=0: suffix=12×2=24, ans[0]=1×24=24
// ans[3] untouched → stays 6 ✓
// ans = [24, 12, 8, 6] ✓


// ── COMPARISON ───────────────────────────────────────────────────
// Approach 1 — Brute Force       : O(n²) time | O(n)  space → TLE
// Approach 2 — Prefix + Suffix   : O(n)  time | O(n)  space → passes
// Approach 3 — Running Suffix    : O(n)  time | O(1)  space → best ✓


// ── TRAPS ────────────────────────────────────────────────────────
// ❌ init prefix[0] or suffix[n-1] to 0 → entire array becomes 0
// ❌ init ans to 0                       → entire array becomes 0
// ✅ always init to 1 — multiplicative neutral element
// ❌ using division                      → not allowed per constraints


int main() {

    // test case 1 — expected: [24, 12, 8, 6]
    vector<int> nums1 = {1, 2, 3, 4};

    cout << "Test 1 brute:     ";
    for(int x : bruteForce(nums1))        cout << x << " "; cout << endl;

    cout << "Test 1 arrays:    ";
    for(int x : prefixSuffixArrays(nums1)) cout << x << " "; cout << endl;

    cout << "Test 1 optimized: ";
    for(int x : optimized(nums1))         cout << x << " "; cout << endl;

    cout << endl;

    // test case 2 — expected: [0, 0, 9, 0, 0]
    vector<int> nums2 = {-1, 1, 0, -3, 3};

    cout << "Test 2 brute:     ";
    for(int x : bruteForce(nums2))        cout << x << " "; cout << endl;

    cout << "Test 2 arrays:    ";
    for(int x : prefixSuffixArrays(nums2)) cout << x << " "; cout << endl;

    cout << "Test 2 optimized: ";
    for(int x : optimized(nums2))         cout << x << " "; cout << endl;

    return 0;
}