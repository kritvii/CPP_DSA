/*
PYRAMID PATTERN

        1|
      1 2| 1
    1 2 3| 2 1
  1 2 3 4| 3 2 1

Divide into 2 parts left and right


3 loops 
space :n-i-1 times ---->" "  

nums1 : j=(1 to i+1)--->cout<<j        

nums2 : j=(i to 1) backwards. (i times)
        cout<<j
        
*/

#include<iostream>
using namespace std;

int main(){
    int n=4;
    for(int i=0;i<n;i++){ //no of lines

        //spaces:n-i-1
        for(int j=0; j<n-i-1; j++){
            cout<<" ";
        }

        //nums1 l.h.s (i+1) times
        for(int j=1;j<=i+1;j++){
            cout<<j;
        }

        //num2 r.h.s
        //backwards (i to 1) times

        for(int j=i; j>0; j--){
            cout<<j;
        }
        cout<<endl;

    }
    return 0;
}