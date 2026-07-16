#include<iostream>
using namespace std;

int main(){
    int no;
    cout<<"enter a no: ";
    cin>>no;

    long fact=1;
    for(int i=1;i<=no;i++){
        fact=fact*i;
    }
    cout<<"factorial of "<<no<<" is "<<fact<<endl;
    return 0;

}