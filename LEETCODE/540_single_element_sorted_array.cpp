// LC 540 - Single Element in a Sorted Array
// Pattern : Binary Search
// Time    : O(log n)  |  Space : O(1)

// WHY O(log n)?
// every iteration we throw away HALF the remaining elements
// number of times you can halve n until reaching 1 = log₂(n)

// Core idea: before single element, pairs start at EVEN indices
// after single element, pairs start at ODD indices
// if mid is even → nums[mid-1]==nums[mid] → pair broken → go left
// if mid is odd  → nums[mid-1]==nums[mid] → pair intact → go right

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int n = nums.size();

        // edge case: only one element → it's the single element
        if(n == 1) return nums[0];

        int st  = 0;
        int end = n - 1;

        while(st <= end) {

            int mid = st + (end - st) / 2;

            // corner case: mid is first element
            if(mid == 0 && nums[0] != nums[1]) return nums[mid];

            // corner case: mid is last element
            if(mid == n-1 && nums[n-1] != nums[n-2]) return nums[mid];

            // mid is the single element — neither neighbour matches
            if(nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1]) {
                return nums[mid];
            }

            // mid is even → pair should be (mid, mid+1)
            // nums[mid-1]==nums[mid] → pair broken on left → go left
            // else                   → pair intact → go right
            if(mid % 2 == 0) {
                if(nums[mid-1] == nums[mid]) {
                    end = mid - 1;
                } else {
                    st = mid + 1;
                }
            } else {
                // mid is odd → pair should be (mid-1, mid)
                // nums[mid-1]==nums[mid] → pair intact → go right
                // else                   → pair broken → go left
                if(nums[mid-1] == nums[mid]) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        return -1;
    }
};

// DRY RUN: [3, 3, 7, 7, 10, 11, 11]  single=10 at index 4
// st=0, end=6, mid=3 → odd → nums[2]=7==nums[3]=7 → st=4
// st=4, end=6, mid=5 → odd → nums[4]=10≠nums[5]=11 → end=4
// st=4, end=4, mid=4 → nums[3]=7≠nums[4]=10≠nums[5]=11 → return 10 ✓

// DRY RUN: [1, 1, 2, 3, 3]  single=2 at index 2
// st=0, end=4, mid=2 → even → nums[1]=1≠nums[2]=2, nums[2]=2≠nums[3]=3
//   → return nums[2] = 2 ✓

// TRAPS:
// ❌ not handling n==1 → loop breaks on corner case checks
// ❌ not handling mid==0 or mid==n-1 → nums[mid-1] or nums[mid+1] out of bounds
// ✅ handle all 3 corner cases before core logic
// ❌ return -1 never actually reached → but needed for compiler