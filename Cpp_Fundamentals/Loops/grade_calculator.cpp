#include<iostream>
using namespace std;

int main(){
    int marks;
    cout<<"Enter marks: ";
    cin>>marks;

    if(marks>=90){
        cout<<"GRADE A\n";
    } else if(marks>=60 && marks<90){
        cout<<"GRADE B\n";
    } else if(marks>=40 && marks<60){
        cout<<"GRADE C\n ";
    }else{
        cout<<"fail\n";
    }
    return 0;
}