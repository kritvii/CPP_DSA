#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// 3 SUM - Brute Force
// find all unique triplets that sum to 0
// Time : O(n³)  — 3 nested loops → TLE on large inputs
// Space: O(n)   — set stores unique triplets

// WHY SET?
// set uses BST internally → keeps elements sorted and unique
// insert duplicate → ignored silently → no manual check needed

// WHY SORT TRIPLET BEFORE INSERT?
// [-1,0,1] and [1,-1,0] are same triplet
// after sorting both become [-1,0,1]
// set treats them as equal → stores only once

vector<vector<int>> threeSum(vector<int>& nums) {

    int n = nums.size();
    set<vector<int>> s;  // stores unique triplets only

    // check every possible combination of 3 elements
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            for(int k = j+1; k < n; k++) {

                // only process triplets that sum to 0
                if(nums[i] + nums[j] + nums[k] == 0) {

                    vector<int> trip = {nums[i], nums[j], nums[k]};

                    // sort before inserting
                    // [-1,0,1] and [1,-1,0] → both become [-1,0,1] after sort
                    sort(trip.begin(), trip.end());

                    // set ignores duplicates automatically
                    s.insert(trip);
                }
            }
        }
    }

    // convert set → vector
    // s.begin() → first element
    // s.end()   → past last element
    // copies all elements from set into new vector
    return vector<vector<int>>(s.begin(), s.end());
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
// i=0,j=1,k=2: -1+0+1=0   → [-1,0,1]  → sort → [-1,0,1]  → insert ✓
// i=0,j=3,k=4: -1+2-1=0   → [-1,2,-1] → sort → [-1,-1,2] → insert ✓
// i=1,j=2,k=4:  0+1-1=0   → [0,1,-1]  → sort → [-1,0,1]  → exists → ignored ✓
// result = [[-1,-1,2],[-1,0,1]] ✓

// WHY TLE ON LARGE INPUTS?
// n=3000 → 3000³ = 27 billion operations → too slow
// use two pointer approach → O(n²) → optimal


//-----------------------------------------------------------------------

/*
LEETCODE: 3 sum brute force approach:
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();

        set<vector<int>>s; //handles duplicates
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                 for(int k = j+1; k < n; k++) {
                    if(nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> trip = {nums[i], nums[j], nums[k]};
                        sort(trip.begin(), trip.end());// sort before inserting
                        s.insert(trip);  // set handles duplicates automatically
            }
        }
    }
}
return vector<vector<int>>(s.begin(), s.end());
// "create a new vector by copying everything from s.begin() to s.end()"
// copies all elements from set into a new vector   
    }
};

*/