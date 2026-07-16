// LC 33 - Search in Rotated Sorted Array
// Pattern : Modified Binary Search
// Time    : O(log n)  |  Space : O(1)

// WHY O(log n)?
// every iteration we throw away HALF the remaining elements
//   end = mid-1  → throw away right half
//   st  = mid+1  → throw away left half
// so for n=1,000,000 elements → only ~20 iterations
// number of times you can halve n until reaching 1 = log₂(n)

// Core idea: at every mid, ONE half is always fully sorted
// check which half is sorted → check if target lies in that range
// if yes → search there | if no → search the other half
// mid is recalculated every iteration based on updated st and end

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int st  = 0;
        int end = nums.size() - 1;

        while(st <= end) {

            // recalculated every iteration based on updated st and end
            int mid = st + (end - st) / 2;

            // target found → return index immediately
            if(nums[mid] == target) return mid;

            // left half is sorted
            if(nums[st] <= nums[mid]) {

                // target lies within left sorted range → go left
                if(nums[st] <= target && target < nums[mid])
                    end = mid - 1;
                else
                    st = mid + 1;  // target not in left → go right

            } else {

                // right half is sorted
                // target lies within right sorted range → go right
                if(nums[mid] < target && target <= nums[end])
                    st = mid + 1;
                else
                    end = mid - 1; // target not in right → go left
            }
        }

        // st > end → target not found
        return -1;
    }
};

// DRY RUN: nums=[4,5,6,7,0,1,2], target=0
// iter 1: st=0, end=6, mid=3, nums[3]=7 ≠ 0
//         left sorted (4<=7) → 4<=0? NO → go right → st=4
// iter 2: st=4, end=6, mid=5, nums[5]=1 ≠ 0
//         left sorted (0<=1) → 0<=0 && 0<1? YES → go left → end=4
// iter 3: st=4, end=4, mid=4, nums[4]=0 == 0 → return 4 ✓

// TRAPS:
// ❌ checking sorted half BEFORE checking nums[mid]==target
// ✅ always check nums[mid]==target first
// ❌ using mid = (st+end)/2 → overflow for large values
// ✅ use mid = st + (end-st)/2