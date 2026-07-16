//operators and typecasting
//note:int/int=int
//eg:5/2=2

//to get proper division with take two diff data types
//like int/float and final answer will be store in larger data type(no of bytes)

#include <iostream>
using namespace std;

int main(){
    int a=5;
    double b=2;

    cout<<(a/b)<<endl;//2.5
    cout<<(10/double(3))<<endl;//typecasting ans:3.333
    
    return 0;
}