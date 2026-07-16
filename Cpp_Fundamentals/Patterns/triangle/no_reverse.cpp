#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter no of lines: ";
    cin>>n;

    for(int i=0;i<n;i++){
        for(int j=i+1;j>0;j--){
            cout<<j<<" ";

        }
        cout<<endl;
    }
    return 0;
}

/*
1 
2 1 
3 2 1 
4 3 2 1 
5 4 3 2 1 
*/