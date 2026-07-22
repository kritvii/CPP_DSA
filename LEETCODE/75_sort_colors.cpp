// LC 75 - Sort Colors
// Pattern : Dutch National Flag Algorithm / 3 Pointers
// Time    : O(n)  |  Space : O(1)

// WHY IS IT CALLED DUTCH NATIONAL FLAG?
// proposed by Dutch computer scientist Edsger Dijkstra
// Dutch flag has 3 stripes → red, white, blue
// problem: arrange balls of 3 colors in that order — just like the flag
// in LC 75: 0=red, 1=white, 2=blue → same problem, numbers instead of colors

// WHY O(n)?
// single pass through the array — each element is visited at most twice

// Core idea: 3 pointers dividing array into 4 sections
// [0...low-1]   → all 0s (red)
// [low...mid-1] → all 1s (white)
// [mid...high]  → unknown
// [high+1...n-1]→ all 2s (blue)

// nums[mid]==0 → swap with low, low++, mid++
// nums[mid]==1 → mid++
// nums[mid]==2 → swap with high, high-- (mid stays — recheck swapped element)

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int low  = 0;
        int mid  = 0;
        int high = nums.size() - 1;

        while(mid <= high) {

            if(nums[mid] == 0) {
                // 0 belongs to left section → swap with low
                // both pointers move forward
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1) {
                // 1 already in correct middle section
                mid++;
            }
            else {
                // 2 belongs to right section → swap with high
                // mid stays — swapped element needs to be rechecked
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

// DRY RUN: [2, 0, 2, 1, 1, 0]
// low=0, mid=0, high=5
// nums[0]=2 → swap(0,5) → [0,0,2,1,1,2], high=4
// nums[0]=0 → swap(0,0) → [0,0,2,1,1,2], low=1, mid=1
// nums[1]=0 → swap(1,1) → [0,0,2,1,1,2], low=2, mid=2
// nums[2]=2 → swap(2,4) → [0,0,1,1,2,2], high=3
// nums[2]=1 → mid=3
// nums[3]=1 → mid=4
// mid=4 > high=3 → loop ends
// result: [0, 0, 1, 1, 2, 2] ✓

// TRAPS:
// ❌ elif         → Python syntax, use else if in C++
// ❌ moving mid++ → when swapping with high skips unchecked element
// ✅ mid stays    → recheck swapped element from high