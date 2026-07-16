#include <iostream>
using namespace std;

//function definition

//void function--> if nothing is returned
//int fucntion--->integer is returned


// void printHello(){
    // cout<<"hi\n"
// }

int printHello(){
    cout<<"hello\n" ;
    return 10;
}
int main(){
    //function call/invoke
   // printHello();

    //to store returned value
    int val=printHello();
    cout<<"value= "<<val<<endl;
    /*
    What happens:
        printHello() runs
        Prints "hello"
        Returns 10
        10 is stored in val
        cout prints val*/


    //direct method
    cout<<printHello()<<endl;
    return 0;
    /*What happens:
        printHello() runs
        Prints "hello"
        Returns 10
        cout prints the returned value*/
}

//output:
//hello
//10