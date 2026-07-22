#include<iostream>
#include<vector>   // needed for std::vector — don't rely on implicit includes
using namespace std;

// Brute Force Approach: O(n log n) -> just call sort() directly
// Optimised (Counting) Approach: O(n) time, O(1) space -> two passes over array
//   Pass 1: count occurrences of 0, 1, 2
//   Pass 2: overwrite array using those counts (0s first, then 1s, then 2s)
void sortColors(vector<int>& nums){
    // sort(nums.begin(), nums.end()); // brute force: O(n log n), not used here

    int n = nums.size();
    int count_0 = 0, count_1 = 0, count_2 = 0;

    // Pass 1: count how many 0s, 1s, and 2s exist -> O(n)
    for(int i=0; i<n; i++){
        if(nums[i] == 0) count_0++;
        else if(nums[i] == 1) count_1++;
        else count_2++;
    }

    // Pass 2: overwrite the array in sorted order using the counts -> O(n)
    int idx = 0;
    for(int i=0; i<n; i++){
        nums[idx++] = 0; // place all 0s first
    }
    for(int i=0; i<count_1; i++){
        nums[idx++] = 1; // then all 1s
    }
    for(int i=0; i<count_2; i++){
        nums[idx++] = 2; // then all 2s
    }
}

int main(){
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sortColors(nums);
    for(int i=0; i<nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}

/*
Dry Run
Initial array: {2, 0, 2, 1, 1, 0} , n = 6

Pass 1 (counting):
    i=0: nums[0]=2 -> count_2=1
    i=1: nums[1]=0 -> count_0=1
    i=2: nums[2]=2 -> count_2=2
    i=3: nums[3]=1 -> count_1=1
    i=4: nums[4]=1 -> count_1=2
    i=5: nums[5]=0 -> count_0=2
    Final counts: count_0=2, count_1=2, count_2=2

Pass 2 (overwrite):
    idx=0: place 0 -> nums[0]=0, idx=1
    idx=1: place 0 -> nums[1]=0, idx=2   (count_0 loop done, 2 zeros placed)
    idx=2: place 1 -> nums[2]=1, idx=3
    idx=3: place 1 -> nums[3]=1, idx=4   (count_1 loop done, 2 ones placed)
    idx=4: place 2 -> nums[4]=2, idx=5
    idx=5: place 2 -> nums[5]=2, idx=6   (count_2 loop done, 2 twos placed)

Final sorted array: {0, 0, 1, 1, 2, 2}
*/