#include<iostream>
using namespace std;

int main(){
    int n;//no of lines
    cout<<"no of lines: ";
    cin>>n;

    for(int i=0;i<n;i++){
        for(int j=1;j<=n;j++){
            cout<<j<<" " ;
        }
        cout<<endl; //inside outer loop
    }
    return 0;
}