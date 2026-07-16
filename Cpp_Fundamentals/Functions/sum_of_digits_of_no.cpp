/*
SUM OF DIGITS OF A NUMBER

logic:
1.num%10=>remainder=>digit
2.num=num/10
3.repeat step 1

num=145%10=5
num=14%10=4
num=1%10=1
num=0
*/


#include<iostream>
using namespace std;

int DigitSum(int num){
    int sum_of_digit=0;
    while (num>0){
        int digit=num%10;
        num/=10;

        sum_of_digit+=digit;
    }
    return sum_of_digit;
}


int main(){
    cout<<"sum= "<<DigitSum(1463)<<endl;//14
    return 0;
}