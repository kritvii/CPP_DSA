#include <iostream>
using namespace std;

int main(){
    int age;
    cout<<"Enter your age: ";
    cin>>age;

    if (age>=18){
        cout<<"Eligible for voting\n";
    }else{
        cout<<"Not eligible for voting\n";
    }
    return 0;
}
