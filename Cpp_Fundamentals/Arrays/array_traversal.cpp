#include<iostream>
using namespace std;

int main(){
    int marks[5]={99,89,79,69,59};
    
    //size of thearray if its not mentioned 
    int size= sizeof(marks)/sizeof(int);

    //loops:0 to size-1
    for(int i=0;i<size;i++){
        cout<<marks[i]<<endl;
    }
    return 0;
}
