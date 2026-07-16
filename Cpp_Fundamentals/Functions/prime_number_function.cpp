//write a function to check if a no is prime or not
//and then printing it (2 to n)

#include<iostream>
using namespace std;

bool isPrime(int n){
    if (n<2){
        return false;
    }else{
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return false;
            }

        }
        return true;
    }
}

//printing prime nos
void printPrime(int n){

    for(int i=2;i<=n;i++){
        if(isPrime(i)){
            cout<<i<<" ";
        }
    }

}

int main(){
    int n;
    cout<<"enter n: ";
    cin>>n;

    printPrime(n);
    return 0;
}