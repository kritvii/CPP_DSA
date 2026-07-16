#include<iostream>
using namespace std;

int main(){
    int n=5;
    for(int i=1;i<=n;i++){ //-->lines
        int m=3;
        for(int j=1;j<=m;j++){//no of stars
            cout<<"*";
        }
        cout << endl;
     }
}

/*
    int m=5;//no of stars
    for(int i=1;i<=m;i++){ 
        cout<<"*"<<" "; //same line
    }
    cout<<endl;
    return 0;
}
*/