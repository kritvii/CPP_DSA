  //LINEAR SEARCH IN 2D ARRAY
  //  in array=>indexing
  //  in 2d array=>row and column indexing=>cell(i,j)

  /*
  return pair
  
  pair<int,int> linearSearch2d(...) {
    ...
    return {i, j};   // i → first, j → second
    ...
    return {-1, -1}; // not found
}

pair<int,int> result = linearSearch2d(...);

result.first   // row index
result.second  // col index

if(result.first != -1)  // check if found

*/
  
#include <iostream>
using namespace std;

pair<int,int> linearSearch2d(int matrix[][3],int rows,int cols,int target){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if (matrix[i][j]==target){
                return {i,j};
                
            }
        }
    }
    return {-1,-1};
}

int main(){
    int matrix[4][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}
    };

    int rows=4;
    int cols=3;
    int target;

    cout<<"Enter the target element to search: ";
    cin>>target;
    pair<int,int> result = linearSearch2d(matrix, rows, cols, target);
    if (result.first != -1) {
        cout << "Element found at row: " << result.first << ", column: " << result.second << endl;
    } else {
        cout << "Element not found in the matrix." << endl;
    }
    cout<<endl;
}












