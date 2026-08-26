#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 3 SUM - Two Pointers (Optimal)
// Time : O(n²)  |  Space : O(1)
// WHY BETTER THAN HASHING?
// same O(n²) time but O(1) space vs O(n) → no extra hashset needed

// Core idea:
// sort array → fix i → two pointers left=i+1, right=n-1
// sum<0  → left++  (need bigger)
// sum>0  → right-- (need smaller)
// sum==0 → store triplet, skip duplicates

vector<vector<int>> threeSum(vector<int>& nums) {

    vector<vector<int>> result;
    int n = nums.size();

    // sort first — enables two pointers + adjacent duplicates easy to skip
    sort(nums.begin(), nums.end());

    for(int i = 0; i < n; i++) {

        // skip duplicate i — same nums[i] gives same triplets again
        // i>0 guard prevents checking nums[-1]
        if(i > 0 && nums[i] == nums[i-1]) continue;

        // early exit — array sorted, if nums[i]>0
        // left and right also positive → sum never 0
        if(nums[i] > 0) break;

        int left  = i + 1;  // starts just after i
        int right = n - 1;  // starts at end

        while(left < right) {

            int sum = nums[i] + nums[left] + nums[right];

            if(sum < 0) {
                left++;   // sum too small → need bigger → move left forward
            }
            else if(sum > 0) {
                right--;  // sum too big → need smaller → move right backward
            }
            else {
                // sum==0 → valid triplet found!
                result.push_back({nums[i], nums[left], nums[right]});
                left++;
                right--;

                // skip duplicate left → same triplet added again
                while(left < right && nums[left] == nums[left-1])
                    left++;

                // skip duplicate right → same triplet added again
                while(left < right && nums[right] == nums[right+1])
                    right--;
            }
        }
    }

    return result;
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
// sorted: [-4,-1,-1,0,1,2]
// i=0: nums[i]=-4, left=1, right=5 → no pair sums to 4
// i=1: nums[i]=-1, left=2, right=5
//   sum=-1+(-1)+2=0 → [-1,-1,2] ✓ left=3,right=4
//   sum=-1+0+1=0    → [-1,0,1]  ✓ left=4,right=3 → stop
// i=2: nums[2]=-1==nums[1]=-1 → skip
// i=3: nums[i]=0, 0+1+2=3>0 → right-- → stop
// result = [[-1,-1,2],[-1,0,1]] ✓

// TRAPS:
// ❌ not sorting → two pointers won't work
// ❌ not skipping duplicate i → same triplets added multiple times
// ❌ not skipping duplicate left/right → same triplets added multiple times
// ✅ always sort first, skip duplicates at all 3 levels