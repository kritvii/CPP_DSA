#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter no of lines: ";
    cin>>n;

    int num=1;
    for(int i=0;i<n;i++){//no of lines
        for(int j=0 ; j<i+1; j++){
        //for(int j=i+1;j>0;j--){
        
            cout<<num<<" ";
            num++;

        }
        cout<<endl;

    }
    return 0;
}

/*
1
2 3
4 5 6
7 8 9 10

initialising num=1 outside both loops
it will give same output with both frontwards and backwards(j++ or j--)
*/