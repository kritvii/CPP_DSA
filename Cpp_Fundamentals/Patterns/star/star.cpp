#include<iostream>
using namespace std;

int main(){
    int n;//no of lines
    cout<<"no of lines: ";
    cin>>n;

    for(int i=1;i<=n;i++){

        int m=3; //no of stars in each row
        for(int j=1;j<=m;j++){
            cout<<"*" ;
        }
        cout<<endl; //inside outer loop
    }
    

    return 0;
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