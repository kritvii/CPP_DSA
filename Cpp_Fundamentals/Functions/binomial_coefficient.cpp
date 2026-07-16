/*
CALC nCr BINOMIAL COEFFECIENT FOR n & r

nCr= n!
    ----
    (n-r)!r!
*/

int factorial(int n){
    int fact=1;
    for(int i=1;i<=n;i++){
        fact*=i;
    }
    return fact;
}

int nCr(int n,int r){
    int fact_n=factorial(n);
    int fact_r=factorial(r);
    int fact_nr=factorial(n-r);
    return fact_n/(fact_r * fact_nr);
}
    

#include<iostream>
using namespace std;

int main(){
    int n=8,r=2;
    cout<<nCr(n, r)<<endl;
    return 0;
}