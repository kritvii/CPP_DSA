/*
MAX SUBARRAY SUM
having time complexity-O(n^2)
But this is not Kadane's algorithm yet.

This is the better brute-force approach.
*/

#include <iostream>
#include<vector>
using namespace std;

//for st=0:end=0,1,2,3,4
//for st=1:end=1,2,3,4
//for st=2:end=2,3,4
//for st=3:end=3,4
//for st=4:end=4

int main(){
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);//5

    int maxSum=INT_MIN;

    for(int st=0;st<n;st++){
        int currSum=0;
        for(int end=st;end<n;end++){
            currSum+=arr[end];
            maxSum=max(currSum,maxSum);
        }
    }

    cout<<"max subarray sum= "<< maxSum<<endl;//15
    return 0;
}


/*
dry run:

Array:

1 2 3 4 5

Initially:

maxSum = INT_MIN
st = 0
currSum = 0
end = 0
currSum = 1

maxSum = max(INT_MIN, 1)
       = 1
end = 1
currSum = 3

maxSum = max(1, 3)
       = 3
end = 2
currSum = 6

maxSum = 6
end = 3
currSum = 10

maxSum = 10
end = 4
currSum = 15

maxSum = 15
st = 1

Reset:

currSum = 0
end = 1
currSum = 2

maxSum = max(15, 2)
       = 15

No change.

end = 2
currSum = 5

maxSum = 15
end = 3
currSum = 9

maxSum = 15
end = 4
currSum = 14

maxSum = 15

Still no change.

The remaining iterations also won't exceed 15, so the final answer is:

Maximum Subarray Sum = 15

which is correct because the whole array is positive.
*/