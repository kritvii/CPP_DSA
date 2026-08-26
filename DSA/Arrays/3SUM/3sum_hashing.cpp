#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

// 3 SUM - Hashing Approach
// Time : O(n²)  |  Space : O(n)
// fix i → fix j → third = -(nums[i]+nums[j])
// check if third exists in hashset
// WHY UNORDERED_SET FOR SEEN?
// O(1) lookup → faster than set O(log n)
// WHY SET FOR RESULT?
// handles duplicate triplets automatically

vector<vector<int>> threeSum(vector<int>& nums) {

    int n = nums.size();
    set<vector<int>> result;  // handles duplicate triplets

    for(int i = 0; i < n; i++) {

        // fresh hashset for every i
        // stores elements we've already passed while scanning j
        unordered_set<int> seen;

        for(int j = i+1; j < n; j++) {

            // third element needed to make sum = 0
            // nums[i] + nums[j] + third = 0
            // third = -(nums[i] + nums[j])
            int third = -(nums[i] + nums[j]);

            // check if third exists in seen
            // count() returns 1 if exists, 0 if not
            if(seen.count(third)) {
                vector<int> trip = {nums[i], nums[j], third};
                sort(trip.begin(), trip.end());  // sort before inserting
                result.insert(trip);             // set handles duplicates
            }

            // add nums[j] AFTER checking
            // WHY AFTER?
            // if added before → third might equal nums[j] → same element used twice
            // eg: nums[i]=0, nums[j]=0, third=0
            // adding before → seen={0} → third=0 found → wrong! [0,0,0] from same element
            // adding after  → seen={} → third=0 not found → correct ✓
            seen.insert(nums[j]);
        }
    }

    return vector<vector<int>>(result.begin(), result.end());
}

int main() {

    // test case 1 — expected: [[-1,-1,2],[-1,0,1]]
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans1 = threeSum(nums1);
    cout << "Test 1: ";
    for(auto trip : ans1) {
        cout << "[";
        for(int x : trip) cout << x << " ";
        cout << "] ";
    }
    cout << endl;

    // test case 2 — expected: []
    vector<int> nums2 = {0, 1, 1};
    vector<vector<int>> ans2 = threeSum(nums2);
    cout << "Test 2: ";
    for(auto trip : ans2) {
        cout << "[";
        for(int x : trip) cout << x << " ";
        cout << "] ";
    }
    cout << endl;

    // test case 3 — expected: [[0,0,0]]
    vector<int> nums3 = {0, 0, 0};
    vector<vector<int>> ans3 = threeSum(nums3);
    cout << "Test 3: ";
    for(auto trip : ans3) {
        cout << "[";
        for(int x : trip) cout << x << " ";
        cout << "] ";
    }
    cout << endl;

    return 0;
}

// DRY RUN: [-1,0,1,2,-1,-4]
// i=0, nums[i]=-1
//   j=1, nums[j]=0,  third=1,  seen={} → not found → seen={0}
//   j=2, nums[j]=1,  third=0,  seen={0} → found! → [-1,0,1] ✓
//   j=3, nums[j]=2,  third=-1, seen={0,1} → not found → seen={0,1,2}
//   j=4, nums[j]=-1, third=2,  seen={0,1,2} → found! → [-1,-1,2] ✓
// result = [[-1,-1,2],[-1,0,1]] ✓

// TRAPS:
// ❌ adding nums[j] to seen BEFORE checking → same element used twice
// ✅ add nums[j] to seen AFTER checking