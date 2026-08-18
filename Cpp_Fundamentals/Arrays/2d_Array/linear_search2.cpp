#include <iostream>
#include <vector>
using namespace std;

// LINEAR SEARCH IN 2D ARRAY
// using vector — works for any size matrix
// returns pair(row, col) if found, pair(-1,-1) if not found

pair<int,int> linearSearch2d(vector<vector<int>>& matrix, int target) {

    int rows = matrix.size();       // number of rows
    int cols = matrix[0].size();    // number of columns

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(matrix[i][j] == target) {
                return {i, j};   // found → return position
            }
        }
    }
    return {-1, -1};  // not found
}

int main(){

    // 4x3 matrix
    vector<vector<int>> matrix1 = {
        {1,  2,  3},
        {4,  5,  6},
        {7,  8,  9},
        {10, 11, 12}
    };

    // 3x4 matrix — different size, same function works!
    vector<vector<int>> matrix2 = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12}
    };

    int target;
    cout << "Enter target: ";
    cin  >> target;

    // test on matrix1
    pair<int,int> result1 = linearSearch2d(matrix1, target);
    if(result1.first != -1)
        cout << "Matrix1 → Found at row=" << result1.first << ", col=" << result1.second << endl;
    else
        cout << "Matrix1 → Not found!" << endl;

    // test on matrix2
    pair<int,int> result2 = linearSearch2d(matrix2, target);
    if(result2.first != -1)
        cout << "Matrix2 → Found at row=" << result2.first << ", col=" << result2.second << endl;
    else
        cout << "Matrix2 → Not found!" << endl;

    return 0;
}

// DRY RUN: target=8, matrix1(4x3)
// i=0: 1,2,3 → no match
// i=1: 4,5,6 → no match
// i=2: 7,8 → match! → return {2,1} ✓
// output: Found at row=2, col=1

// DRY RUN: target=8, matrix2(3x4)
// i=0: 1,2,3,4 → no match
// i=1: 5,6,7,8 → match at j=3 → return {1,3} ✓
// output: Found at row=1, col=3