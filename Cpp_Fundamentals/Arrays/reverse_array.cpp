/*
REVERSING AN ARRAY

if arr[]={1,2,3,4,5}
output: [5,4,3,2,1]

using 2 pointer approach
start=0 ; end=size-1
(++)        (--)

while (start<end){
    swap(arr[start],arr[end])
    start++ ;end-- ;
}


if arr[] has odd no of elements
stop swapping when start==end 

if arr[] has even no of elements
stop swapping when start >end 
*/

#include<iostream>
using namespace std;

void ReverseArray(int arr[], int sz){
    int start=0, end=sz-1;

    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[]={10,20,30,40,50};
    ReverseArray(arr,5);

   //ReverseArray(arr[],2)<<endl;
   //20 10 30 40 50
    return 0;
}