//OPERATIONS

//note:int/int=int
//eg:5/2=2

//to get proper division with take two diff data types
//like int/float and final answer will be store in larger data type(no of bytes)

#include<iostream>
using namespace std;

int main(){
   // int a=5,b=10;
    //int sum=a+b;
    //cout<<"Sum is:"<<sum<<endl;

    //first always define the data type
    int a,b;
    cout<<"enter value of a :";
    cin>>a;//60
    cout<<"enter value of b :";
    cin>>b;//1.6
    cout<<"sum= "<< (a+b) <<endl; //61
    cout<<"difference= "<< (a-b) <<endl; //59
    cout<<"modulus= "<<(a%b)<<endl; //0
    cout<<"product= "<<(a*b)<<endl; //60
    cout<<"divison ="<<(a/b)<<endl; //60

    
    return 0;
}