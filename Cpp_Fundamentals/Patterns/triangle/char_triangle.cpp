#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter no of lines: ";
    cin>>n;
    char ch='A';

    for(int i=0;i<n;i++){
         for(int j=0;j<i+1;j++){ //i+1 times
            cout<<ch<<" ";
            
         } 
         ch++; //IN THE OUTER LOOP(very imp)
         cout<<endl;

    }
   
    return 0;
}

/*if we would have kept ch++ inside the inner 
loop then the pattern would be:

A
B C
D E F
but we didin't need that 


/*
OUTPUT:
A
B B
C C C*/