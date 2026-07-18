// LC 238 - Product of Array Except Self
// Approach : Brute Force
// Time     : O(n²) — TLE on large inputs
// Space    : O(n)  — output array

// Note: this approach is correct but too slow for LC
// constraint requires O(n) — see prefix/suffix approach

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans;  // stores final answer

        // for every index i, calculate product of all OTHER elements
        for(int i = 0; i < n; i++) {

            int prod = 1;  // reset product for each i

            // multiply every element except the one at index i
            for(int j = 0; j < n; j++) {
                if(i != j) {          // skip index i
                    prod *= nums[j];  // multiply everything else
                }
            }

            ans.push_back(prod);  // store result for index i
        }

        return ans;
    }
};

// DRY RUN: [1, 2, 3, 4]
// i=0 → skip j=0, prod = 2×3×4 = 24
// i=1 → skip j=1, prod = 1×3×4 = 12
// i=2 → skip j=2, prod = 1×2×4 = 8
// i=3 → skip j=3, prod = 1×2×3 = 6
// ans = [24, 12, 8, 6] ✓

// WHY IT'S SLOW:
// for n=100,000 → 100,000 × 100,000 = 10 billion operations
// O(n²) gets TLE on LC for large inputs
// fix → use prefix/suffix approach (O(n))