#include <iostream>
using namespace std;

int main() {

    // declaration and initialization
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    /*
    input matrix:
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin>>matrix[i][j];
        }
    }
    */

    // traversal — nested loop
    // outer loop → rows
    // inner loop → columns
    for(int i = 0; i < 3; i++) {        // i = row index
        for(int j = 0; j < 3; j++) {    // j = col index
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // access specific element
    cout << matrix[1][2] << endl;  // 6

    // modify element
    matrix[0][0] = 99;
    cout << matrix[0][0] << endl;  // 99


    //2d array in memory
    /*eg:
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}

         //1.row major: 1 2 3 4 5 6 7 8 9

        //2.column major: 1 4 7 2 5 8 3 6 9

    */

   

    
    

    

    return 0;
}
