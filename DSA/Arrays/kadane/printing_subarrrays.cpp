#include <iostream>
#include<vector>
using namespace std;

int main(){
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);//5

    for(int st=0;st<n;st++){
        //for st=0:end=0,1,2,3,4
        //for st=1:end=1,2,3,4
        //for st=2:end=2,3,4
        //for st=3:end=3,4
        //for st=4:end=4
        
        for(int end=st;end<n;end++){
            //printing of array logic
            for(int i=st;i<=end;i++){
                cout<<arr[i];
            }
            cout<<" ";
        }
        cout<<endl;

    }
}


/*
OUTPUT:
1 12 123 1234 12345 
2 23 234 2345 
3 34 345 
4 45 
5 
*/