#include<iostream>
using namespace std;

bool powerOfTwo(int n){
    if (n<=0) return false;

    while(n>1){

        if(n&1) return false; //odd no
/*
        5 & 1= 1

        5 = 0101
        1 = 0001
       -----------
            0001

       Even numbers always end with 0
       Odd numbers always end with 1
        
*/
       n=n>>1; //divide by 2
    }

    return true;

    
}