/*
UNARY OPERATORS

INCREMENT
a++ : kaam,update (post increment)
++a : update,kaam (pre increment)
*/

#include <iostream>
using namespace std;

/*
int main(){
    int a=10;
    int b=a++; //kaam then update
    cout<<b<<endl;//10
    cout<<a<<endl;//11
    return 0;
}
*/

int main(){
    int a=10;
    int b=++a; //update then kaam
    cout<<b<<endl;//11
    cout<<a<<endl;//11
    return 0;
}
