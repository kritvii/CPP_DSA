//DIAGONAL SUMS OF A 2D MATRIX (primary and secondary, tracked separately, as a function)
#include<iostream>
using namespace std;

// Time Complexity: O(n)   -> single pass through n rows, one element from each diagonal picked per row
// Space Complexity: O(1)  -> just two running sums, no extra data structure
void diagonalSums(int mat[][4], int n, int &primaryDiagonalSum, int &secondaryDiagonalSum){
    for(int i=0; i<n; i++){
        primaryDiagonalSum += mat[i][i];       // row i, col i
        secondaryDiagonalSum += mat[i][n-1-i]; // row i, col (n-1-i)
    }
}

int main(){
    int mat[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    int n = 4;

    int primaryDiagonalSum = 0;
    int secondaryDiagonalSum = 0;

    // passing sums by reference so the function can modify main()'s variables directly
    diagonalSums(mat, n, primaryDiagonalSum, secondaryDiagonalSum);

    cout << "Primary Diagonal Sum: " << primaryDiagonalSum << endl;
    cout << "Secondary Diagonal Sum: " << secondaryDiagonalSum << endl;
    cout << "Combined Total: " << (primaryDiagonalSum + secondaryDiagonalSum) << endl;

    return 0;
}

/*
Dry Run
Matrix (n=4):
 1   2   3   4
 5   6   7   8
 9  10  11  12
13  14  15  16

Before call: primaryDiagonalSum=0, secondaryDiagonalSum=0

i=0: mat[0][0]=1 -> primary=1        mat[0][3]=4 -> secondary=4
i=1: mat[1][1]=6 -> primary=7        mat[1][2]=7 -> secondary=11
i=2: mat[2][2]=11 -> primary=18      mat[2][1]=10 -> secondary=21
i=3: mat[3][3]=16 -> primary=34      mat[3][0]=13 -> secondary=34

Function returns (via reference parameters):
Primary Diagonal Sum: 34
Secondary Diagonal Sum: 34
Combined Total: 68
*/