// LC 54 - Spiral Matrix
// Pattern : Matrix Traversal / 4 Boundaries
// Time    : O(m×n)  |  Space : O(1) extra
// m = number of rows, n = number of columns
// total elements = m×n → every element visited exactly once
// 4 directions together cover all m×n elements → O(m×n)

// Core idea: 4 boundaries shrink inward after each direction
// top    → topmost unvisited row
// bottom → bottommost unvisited row
// left   → leftmost unvisited col
// right  → rightmost unvisited col

// direction 1: left→right along top row    → top++
// direction 2: top→bottom along right col  → right--
// direction 3: right→left along bottom row → bottom--
//              if top>bottom → single row → break (direction 1 already covered it)
// direction 4: bottom→top along left col   → left++
//              if left>right → single col → break (direction 2 already covered it)

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> result;

        int top    = 0;
        int bottom = rows - 1;
        int left   = 0;
        int right  = cols - 1;

        while(left <= right && top <= bottom) {

            // direction 1: left to right along top row
            for(int j = left; j <= right; j++) {
                result.push_back(matrix[top][j]);
            }
            top++;  // top row done → shrink top boundary down

            // direction 2: top to bottom along right col
            for(int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;  // right col done → shrink right boundary left

            // direction 3: right to left along bottom row
            // if top>bottom → single row left → direction 1 already covered it → break
            for(int j = right; j >= left; j--) {
                if(top > bottom) break;
                result.push_back(matrix[bottom][j]);
            }
            bottom--;  // bottom row done → shrink bottom boundary up

            // direction 4: bottom to top along left col
            // if left>right → single col left → direction 2 already covered it → break
            for(int i = bottom; i >= top; i--) {
                if(left > right) break;
                result.push_back(matrix[i][left]);
            }
            left++;  // left col done → shrink left boundary right
        }

        return result;
    }
};

// DRY RUN 1: 3×3 matrix
// matrix = [[1, 2, 3],
//           [4, 5, 6],
//           [7, 8, 9]]
// top=0,bottom=2,left=0,right=2
// dir1: [1,2,3] → top=1
// dir2: [6,9]   → right=1
// dir3: top=1<=bottom=2 → [8,7] → bottom=1
// dir4: left=0<=right=1 → [4]   → left=1
// top=1,bottom=1,left=1,right=1
// dir1: [5] → top=2
// dir2: nothing (top=2>bottom=1)
// dir3: top=2>bottom=1 → break
// dir4: left=1<=right=1 → nothing (i=0<top=2)
// result = [1,2,3,6,9,8,7,4,5] ✓

// DRY RUN 2: 1×4 matrix (single row)
// matrix = [[1, 2, 3, 4]]
// top=0,bottom=0,left=0,right=3
// dir1: [1,2,3,4] → top=1
// dir2: nothing (top=1>bottom=0)
// dir3: top=1>bottom=0 → break → bottom=-1
// dir4: nothing (bottom=-1<top=1)
// result = [1,2,3,4] ✓

// DRY RUN 3: 3×4 matrix
// matrix = [[1,  2,  3,  4],
//           [5,  6,  7,  8],
//           [9, 10, 11, 12]]
// dir1: [1,2,3,4] → top=1
// dir2: [8,12]    → right=2
// dir3: [11,10,9] → bottom=1
// dir4: [5]       → left=1
// top=1,bottom=1,left=1,right=2
// dir1: [6,7] → top=2
// dir2: nothing
// dir3: top=2>bottom=1 → break
// dir4: nothing
// result = [1,2,3,4,8,12,11,10,9,5,6,7] ✓

// TRAPS:
// ❌ no break in direction 3 → single row adds elements twice
// ❌ no break in direction 4 → single col adds elements twice
// ✅ break when top>bottom or left>right → handles edge cases cleanly
// ✅ boundary update (top++, right-- etc) happens AFTER each direction