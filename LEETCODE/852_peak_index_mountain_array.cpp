// LC 852 - Peak Index in a Mountain Array
// Pattern : Binary Search
// Time    : O(log n)  |  Space : O(1)

// WHY O(log n)?
// every iteration we throw away HALF the remaining elements
// number of times you can halve n until reaching 1 = log₂(n)

// Core idea: in a mountain array, peak is where arr[mid-1] < arr[mid] > arr[mid+1]
// if arr[mid-1] < arr[mid] → we are on increasing slope → peak is to the right
// if arr[mid-1] > arr[mid] → we are on decreasing slope → peak is to the left
// mid is recalculated every iteration based on updated st and end

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        // start from 1 and end at size-2
        // peak can never be first or last element in a mountain array
        int st  = 1;
        int end = arr.size() - 2;

        // Continue searching until the search space becomes empty.
        while(st <= end) {

            // recalculated every iteration based on updated st and end
            int mid = st + (end - st) / 2;

            // mid is the peak — both neighbours are smaller
            if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]) {
                return mid;
            }

            // on increasing slope → peak is to the right
            if(arr[mid-1] < arr[mid]) {
                st = mid + 1;
            } else {
                // on decreasing slope → peak is to the left
                end = mid - 1;
            }
        }

        return -1;
    }
};

// DRY RUN: arr = [0, 1, 0]
// st=1, end=1, mid=1
// arr[0]=0 < arr[1]=1 > arr[2]=0 → peak found → return 1 ✓

// DRY RUN: arr = [0, 2, 1, 0]
// st=1, end=2, mid=1
// arr[0]=0 < arr[1]=2 > arr[2]=1 → peak found → return 1 ✓

// DRY RUN: arr = [0, 1, 2, 3, 1, 0]
// st=1, end=4, mid=2 → arr[1]<arr[2], increasing → st=3
// st=3, end=4, mid=3 → arr[2]<arr[3]>arr[4] → return 3 ✓

// TRAPS:
// ❌ st=0, end=size-1 → checking arr[mid-1] when mid=0 → out of bounds
// ✅ st=1, end=size-2 → peak can never be first or last element
// ❌ using mid=(st+end)/2 → overflow for large values
// ✅ use mid = st + (end-st)/2