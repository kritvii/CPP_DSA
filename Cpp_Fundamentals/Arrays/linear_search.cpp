//LINEAR SEARCH
//time complecity=O(n)

//index=-1 invalid index


#include<iostream>
using namespace std;

int LinearSearch(int arr[],int size,int target){
    for(int i=0;i<size;i++){
        if(arr[i]==target){
            return i; //found
        }
    }
    return -1; //not found

}

int main(){
    int arr[]={4,8,9,10};
    int size=4;
    cout<<LinearSearch(arr,size,4)<<endl;//0
    cout<<LinearSearch(arr,2,10)<<endl;//-1
    cout<<LinearSearch(arr,2,15)<<endl;//-1
    cout<<LinearSearch(arr,size,10)<<endl;//3
    cout<<LinearSearch(arr,size,50)<<endl;//-1
    //cus that no is not in the array
    return 0;
}
