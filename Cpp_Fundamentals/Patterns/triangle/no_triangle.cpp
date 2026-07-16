#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter no of lines: ";
    cin>>n;

    for(int i=0;i<n;i++){
         for(int j=0;j<i+1;j++){ //i+1 times
            cout<<i+1<<" ";
         } 
         cout<<endl;

    }
   
    return 0;
}

/*
OUTPUT:
1
2 2
3 3 3*/