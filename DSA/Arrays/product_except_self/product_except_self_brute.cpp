#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {

    int n = nums.size();
    vector<int> ans;

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

int main() {

    // test case 1 — expected: [24, 12, 8, 6]
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> ans1  = productExceptSelf(nums1);
    cout << "Test 1: ";
    for(int x : ans1) cout << x << " ";
    cout << endl;

    // test case 2 — expected: [0, 0, 9, 0, 0]
    vector<int> nums2 = {-1, 1, 0, -3, 3};
    vector<int> ans2  = productExceptSelf(nums2);
    cout << "Test 2: ";
    for(int x : ans2) cout << x << " ";
    cout << endl;

    // test case 3 — expected: [1, 1]
    vector<int> nums3 = {1, 1};
    vector<int> ans3  = productExceptSelf(nums3);
    cout << "Test 3: ";
    for(int x : ans3) cout << x << " ";
    cout << endl;

    return 0;
}

// DRY RUN: [1, 2, 3, 4]
// i=0 → skip j=0, prod = 2×3×4 = 24
// i=1 → skip j=1, prod = 1×3×4 = 12
// i=2 → skip j=2, prod = 1×2×4 = 8
// i=3 → skip j=3, prod = 1×2×3 = 6
// ans = [24, 12, 8, 6] ✓

// WHY IT'S SLOW:
// for n=100,000 → 10 billion operations → TLE on LC
// fix → prefix/suffix approach (O(n))