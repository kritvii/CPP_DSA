// LC 15 - 3Sum
// Approach 3 : Two Pointers (Optimal)
// Time    : O(n²)  |  Space : O(1)

// WHY BETTER THAN HASHING?
// same time complexity O(n²) but O(1) space vs O(n)
// no extra hashset needed — two pointers work in place

// Core idea:
// sort array first → enables two pointers + easy duplicate skipping
// fix i → find pair summing to -nums[i] using two pointers
// sum<0 → left++ (need bigger)
// sum>0 → right-- (need smaller)
// sum==0 → found! skip duplicates for left and right

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n=nums.size();
        vector<vector<int>> result;

        // sort first — enables two pointers + adjacent duplicates easy to skip
        sort(nums.begin(),nums.end());


        for(int i=0;i<n;i++){
            // skip duplicate i — same nums[i] gives same triplets again
            if(i>0 && nums[i]==nums[i-1])continue; 
            int j=i+1, k=n-1;

            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if (sum<0){
                    j++; // sum too small → need bigger → move left forward
                }else if(sum>0){
                    k--; // sum too big → need smaller → move right backward
                }else{
                    // sum==0 → valid triplet found!
                    result.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;

                    // skip duplicate left → same triplet added again
                    while(j<k && nums[j]==nums[j-1]){
                        j++;
                    }
                    // skip duplicate right → same triplet added again
                    while(j < k && nums[k] == nums[k+1])
                        k--;
                }
            }
        }
        return result;
    }
};
// DRY RUN: [-1,0,1,2,-1,-4]
// sorted: [-4,-1,-1,0,1,2]
//
// i=0: nums[i]=-4, left=1, right=5
//   sum=-4+(-1)+2=-3 < 0 → left++
//   sum=-4+(-1)+2=-3 < 0 → left++
//   sum=-4+0+2=-2   < 0 → left++
//   sum=-4+1+2=-1   < 0 → left++
//   left=5==right=5 → stop
//
// i=1: nums[i]=-1, left=2, right=5
//   sum=-1+(-1)+2=0 → [-1,-1,2] ✓ left=3,right=4
//   sum=-1+0+1=0    → [-1,0,1]  ✓ left=4,right=3
//   left>right → stop
//
// i=2: nums[2]=-1==nums[1]=-1 → duplicate → skip
//
// i=3: nums[i]=0 > 0? NO
//   left=4,right=5: 0+1+2=3 > 0 → right--
//   left=4==right=4 → stop
//
// result = [[-1,-1,2],[-1,0,1]] ✓

// TRAPS:
// ❌ not sorting → two pointers won't work
// ✅ always sort first
// ❌ not skipping duplicate i → same triplets added multiple times
// ✅ if(i>0 && nums[i]==nums[i-1]) continue
// ❌ not skipping duplicate left/right → same triplets added multiple times
// ✅ skip duplicates after finding valid triplet