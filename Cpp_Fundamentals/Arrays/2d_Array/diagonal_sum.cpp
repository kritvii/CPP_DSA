#include<iostream>
using namespace std;

pair<int,int> diagonalSum(vector<vector<int>>& mat) {
    int n            = mat.size(); //no of rows=>i
    int primarySum   = 0;
    int secondarySum = 0;

    for(int i = 0; i < n; i++) {
        primarySum   += mat[i][i];      // primary diagonal
        secondarySum += mat[i][n-1-i];  // secondary diagonal
    }

    return {primarySum, secondarySum};  // return both separately
}

int main() {

    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    pair<int,int> result = diagonalSum(mat);

    cout << "Primary diagonal sum:   " << result.first  << endl;  // 15
    cout << "Secondary diagonal sum: " << result.second << endl;  // 15

    return 0;
}