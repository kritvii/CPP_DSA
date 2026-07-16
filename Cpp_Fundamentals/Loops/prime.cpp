#include<iostream>
using namespace std;

int main(){
    int n=7;
    bool isPrime=true;

    for(int i=2 ; i*i<=n; i++){
        if(n%i==0){ //non-prime
            isPrime=false;
            break;
        }
    }
    if(isPrime==true){
        cout<<n<<" is prime no\n";
    }else{
        cout<<n<<" is non prime no\n";
    }
    return 0;
}