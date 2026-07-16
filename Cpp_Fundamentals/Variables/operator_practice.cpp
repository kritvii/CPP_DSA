//another example of operators and typecasting

#include <iostream>
using namespace std;

int main(){
     
    int ans =(5/double(2)); 
    //rhs value 2.5 but lhs datatype is int (typecasting)
    cout<< ans <<endl;//2
     return 0;
}