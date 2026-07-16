//type casting
//big-->small (implicit).       //small --> big(explicit)
//double-->float
//100.99 ->100
#include <iostream>
using namespace std;

int main(){
    double Price=100.99;
    int newPrice=(int)Price;
    cout<< newPrice <<endl;
    return 0;
}
