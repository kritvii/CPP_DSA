//write a function to print nth fibonacci

#include<iostream>
using namespace std;

void printFibonacci(int n){

    int a=0;
    int b=1;

    for(int i=1;i<=n;i++){
        cout<<a<<" ";

        int next = a + b; 
        a=b;
        b=next;
    }
}

int main(){
    int n;
    cout<<"enter till nth fibonnaci series";
    cin>>n;

    printFibonacci(n);
    return 0;
}