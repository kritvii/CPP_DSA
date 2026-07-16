//WHILE LOOP

/*

while(condition){
    true^^
    cout<<"A"}

*/
#include<iostream>
using namespace std;

int main(){
    int n=20;
    int i=1; //initialization

    while(i<=n){
        cout<<i<<" ";//same line
        i++; //if we commen out this the infinite loop(1 1 1 1 1 1 1 1 1 1)
    }
    cout<<"end of program";

/*
So the purpose of endl is:

1. Move the cursor to the next line.
2. Flush the output buffer.
*/
    cout<<"hi"<<endl;
    cout<<"bye";
    return 0;
}
