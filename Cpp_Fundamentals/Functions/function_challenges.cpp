#include<iostream>
using namespace std;

void change(int x){
    x=2*x;
    cout<<"x= "<<x<<endl;//10
}

int main(){
    int x=5;
    change(x);

    cout<<"x= "<<x<<endl; //5
    return 0;
}