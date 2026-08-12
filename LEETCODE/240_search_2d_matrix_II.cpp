/*
Why this approach (staircase search) works, quickly:
Starting at the top-right corner gives you a special property: 
everything to the left is smaller, and everything below is larger. 
So at every cell, you get a clean binary decision — if the target is smaller, eliminate the current column (move left); 
if larger, eliminate the current row (move down). Each step eliminates one row or one column entirely, 
so it takes at most rows + cols steps — hence O(m+n).
*/

// LC 240 - Search a 2D Matrix II
// Pattern : Staircase Search (Top-Right Corner)
// Time    : O(m+n)  |  Space : O(1)

// WHY O(m+n)?
// each step either row++ or col-- → at most m+n steps total

// CORE INSIGHT — WHY TOP-RIGHT CORNER?
// choose an element that has only 2 directions not 4
// middle element → 4 directions (left, right, up, down) → confusing
// top-right OR bottom-left → only 2 directions → easy decision!

// TOP-RIGHT CORNER → matrix[0][cols-1]
// it is the LARGEST in its row   → target < it → move LEFT  (col--)
// it is the SMALLEST in its col  → target > it → move DOWN  (row++)
// only 2 possible moves → clear decision every step

// BOTTOM-LEFT CORNER → matrix[rows-1][0] also works
// it is the SMALLEST in its row  → target > it → move RIGHT (col++)
// it is the LARGEST in its col   → target < it → move UP    (row--)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        // start from top-right corner
        int row = 0;
        int col = cols - 1;

        while(row < rows && col >= 0) {

            if(matrix[row][col] == target) {
                return true;   // found!
            }
            else if(target < matrix[row][col]) {
                col--;   // target smaller → move left (eliminate this column)
            }
            else {
                row++;   // target larger → move down (eliminate this row)
            }
        }

        return false;  // not found
    }
};

// DRY RUN: target=5
// matrix=[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22]...]
// start: row=0, col=4 → matrix[0][4]=15 > 5 → col=3
// row=0, col=3 → matrix[0][3]=11 > 5 → col=2
// row=0, col=2 → matrix[0][2]=7  > 5 → col=1
// row=0, col=1 → matrix[0][1]=4  < 5 → row=1
// row=1, col=1 → matrix[1][1]=5 == 5 → return true ✓

// DRY RUN: target=20
// keeps moving until row>=rows or col<0 → return false ✓

// TRAPS:
// ❌ starting from top-left → 4 directions → ambiguous
// ❌ starting from middle   → 4 directions → ambiguous
// ✅ top-right or bottom-left → only 2 directions → clear decision
// ❌ using LC 74 approach (flatten) → won't work, matrix not sorted row by row