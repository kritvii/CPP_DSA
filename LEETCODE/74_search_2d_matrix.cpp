// LC 74 - Search a 2D Matrix
// Pattern : Binary Search on Flattened Matrix
// Time    : O(log(m×n))  |  Space : O(1)

// WHY O(log(m×n))?
// binary search on m×n elements → log(m×n) steps
// log(m×n) = log m + log n  (logarithm property: log(a×b) = log a + log b)

// Core idea:
// matrix is sorted row by row → if flattened = one sorted array
// treat entire matrix as 1D array → apply binary search
// convert 1D index back to 2D using:
//   row = mid / cols   → integer division → which row
//   col = mid % cols   → remainder → which column within that row

// WHY mid/cols gives row and mid%cols gives col?
// every row has 'cols' elements → think of cinema seats:
//   row 0: seats 0,1,2,3  |  row 1: seats 4,5,6,7
// seat 9 → row=9/4=2, col=9%4=1 → seat 1 in row 2 ✓
// division → complete rows passed | remainder → position in current row

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        // treat matrix as flattened 1D array
        // search space: 0 to rows*cols-1
        int st  = 0;
        int end = (rows * cols) - 1;

        while(st <= end) {

            int mid = st + (end - st) / 2;

            // convert 1D index to 2D coordinates
            // mid=5, cols=4 → row=5/4=1, col=5%4=1 → matrix[1][1]
            int row = mid / cols;
            int col = mid % cols;

            if(matrix[row][col] == target) {
                return true;        // found → return true
            }
            else if(matrix[row][col] < target) {
                st = mid + 1;       // target larger → search right half
            }
            else {
                end = mid - 1;      // target smaller → search left half
            }
        }

        return false;   // search space exhausted → not found
    }
};

// DRY RUN: matrix=[[1,3,5,7],[10,11,16,20],[23,30,34,60]], target=3
// rows=3, cols=4, st=0, end=11
// mid=5 → row=1, col=1 → matrix[1][1]=11 > 3 → end=4
// mid=2 → row=0, col=2 → matrix[0][2]=5  > 3 → end=1
// mid=0 → row=0, col=0 → matrix[0][0]=1  < 3 → st=1
// mid=1 → row=0, col=1 → matrix[0][1]=3 == 3 → return true ✓

// TRAPS:
// ❌ row=mid/rows → wrong! always divide by cols
// ✅ row=mid/cols, col=mid%cols
// ❌ end = rows*cols → off by one
// ✅ end = rows*cols-1
// ❌ only works if matrix sorted row by row (LC 74 guarantee)
// ✅ won't work for LC 240 (sorted rows+cols but not flattened)