//pass by value
//copy of argument is passed to fuction

//changes made in the original function won't affect main function
#include<iostream>
using namespace std;

int sum(int a,int b){
    a=a+10;//15
    b=b+10;//16
    return a+b;//31
}

int main(){
   int  x=5,y=6; //arguments
   cout<<sum(x,y)<<endl;
   //cout<<a<<endl; //cus this parameter was inside the function
                    //not defined
  
  
    cout<<x<<endl; //5

    return 0;
}