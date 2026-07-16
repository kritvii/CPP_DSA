#include<iostream>
using namespace std;

int main(){

    int marks[5]={99,89,79,69,59};

    marks[0]=100; //changing value 

    cout<<marks[0]<<endl;
    cout<<marks[1]<<endl;
    cout<<marks[2]<<endl;
    cout<<marks[3]<<endl;
    cout<<marks[4]<<endl;

    //0 to size-1
    cout<<marks[5]<<endl; //is past the end of the array
    cout<<marks[-1]<<endl; //array index -1 is before the beginning of the array
    return 0;
}