// LC 31 - Next Permutation
// Pattern : Array / Math
// Time    : O(n)  |  Space : O(1)

// WHY O(n)?
// 3 linear scans at most — find pivot, find swap, reverse suffix
// cannot do better than O(n) — must read array at least once

// Core idea: 3 steps
// step 1: find pivot → first element smaller than right neighbour (right to left)
// step 2: find rightmost element > pivot → swap with pivot
// step 3: reverse everything after pivot → gives smallest arrangement

// WHY REVERSE AFTER SWAP?
// after swap, suffix is still in descending order
// reversing gives smallest possible arrangement → O(n) vs sort O(n log n)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n     = nums.size();
        int pivot = -1;

        // step 1: find pivot — scan right to left
        // start at n-2 → nums[i+1] when i=n-1 would be out of bounds
        for(int i = n-2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) {
                pivot = i;
                break;
            }
        }

        // no pivot → array fully descending → reverse entire array
        // eg: [5,4,3,2,1] → [1,2,3,4,5]
        // WHY pivot==-1 for decreasing array?
        // [5, 4, 3, 2, 1]
        // i=3: 2<1? NO
        // i=2: 3<2? NO
        // i=1: 4<3? NO
        // i=0: 5<4? NO
        // no element found where nums[i]<nums[i+1] → pivot stays -1
        // meaning this is already the LARGEST permutation
        // next permutation = smallest = reverse entire array
        if(pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;  // exit early — no more steps needed
        }

        // step 2: find rightmost element > pivot → swap
        // scanning from right gives closest larger element
        for(int i = n-1; i > pivot; i--) {
            if(nums[i] > nums[pivot]) {
                swap(nums[pivot], nums[i]);
                break;  // first from right is correct → stop immediately
            }
        }

        // step 3: reverse suffix after pivot
        // nums.begin()+pivot+1 → one position after pivot
        // suffix is descending after swap → reverse gives ascending
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};

// DRY RUN 1: [1, 2, 5, 4, 3]
// step 1: i=3 → 4>3 skip, i=2 → 5>4 skip, i=1 → 2<5 → pivot=1
// step 2: i=4 → 3>2 → swap(1,4) → [1,3,5,4,2], break
// step 3: reverse from index 2 → [5,4,2] → [2,4,5]
// final: [1,3,2,4,5] ✓

// DRY RUN 2: [5, 4, 3, 2, 1] (fully descending → pivot==-1 case)
// step 1: i=3 → 2<1? NO
//         i=2 → 3<2? NO
//         i=1 → 4<3? NO
//         i=0 → 5<4? NO
//         loop ends → pivot stays -1
// pivot==-1 → already largest permutation → reverse entire array
// [5,4,3,2,1] → [1,2,3,4,5] ✓

// DRY RUN 3: [1, 2, 3] (fully ascending)
// step 1: i=1 → 2<3 → pivot=1
// step 2: i=2 → 3>2 → swap(1,2) → [1,3,2], break
// step 3: reverse from index 2 → [2] → [2]
// final: [1,3,2] ✓

// TRAPS:
// ❌ loop starts at n-1 → nums[i+1] out of bounds
// ✅ loop starts at n-2
// ❌ no return after reverse in pivot==-1 → runs steps 2 and 3 wrongly
// ✅ return immediately after reverse
// ❌ no break in step 2 → keeps swapping wrong elements
// ✅ break after first swap from right
// ❌ using sort() for step 3 → O(n log n)
// ✅ reverse() is enough → O(n) since suffix already descending