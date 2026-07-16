// LC 238 - Product of Array Except Self
// Pattern : Prefix + Suffix Products
// Time    : O(n)  |  Space : O(1) extra

// 3 APPROACHES 
// 1. Brute Force          → O(n²) time | O(n) space  → TLE
// 2. Prefix + Suffix Arrays → O(n) time | O(n) space  → passes
// 3. Prefix + Suffix Variable → O(n) time | O(1) space → best ✓

// Core idea:
// ans[i] = product of everything LEFT of i × product of everything RIGHT of i
// pass 1 → fill ans with prefix products (left to right)
// pass 2 → multiply running suffix variable into ans (right to left)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans(n, 1);  // init to 1 — holds prefix first, then final ans
                                // [1,1,1,1]

        // PASS 1: prefix (left to right) 
        // ans[i] = product of everything LEFT of i
        // ans[0] stays 1 — nothing to the left of index 0
        for(int i = 1; i < n; i++){
            ans[i] = ans[i-1] * nums[i-1];
        }
        // nums = [1,  2,  3,  4]
        // ans  = [1,  1,  2,  6]

        // PASS 2: suffix (right to left) 
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
};

// DRY RUN: [1, 2, 3, 4]
// after pass 1: ans = [1,  1,  2,  6]
// i=2: suffix=1×4=4,   ans[2]=2×4=8
// i=1: suffix=4×3=12,  ans[1]=1×12=12
// i=0: suffix=12×2=24, ans[0]=1×24=24
// ans[3] untouched → stays 6 ✓
// ans = [24, 12, 8, 6] ✓

// TRAPS:
// ❌ init ans to 0   → entire array becomes 0
// ✅ init ans to 1   → multiplicative neutral element
// ❌ using division  → not allowed per constraints