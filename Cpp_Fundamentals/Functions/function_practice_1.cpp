#include<iostream>
using namespace std;

//sum of 2 nos
double sum(double a,double b){ //parameters
    double s=a+b;
    return s;
}

//min of 2 nos
int minOfTwo(int a, int b){
    if(a>b){
        return b;
    }else{
        return a;
    }
}

int sumNos(int n){
    int sum=0;
    for(int i=1;i<=n;i++){
        sum=sum+i;
    }
    return sum;
}

int factorial(int n){
    int fact=1;
    for (int i=1;i<=n;i++){
        fact*=i;
    }
    return fact;
    
    
}
int main(){
    cout<<sum(10.65,5.098)<<endl; //arguments
    cout<<"minimum= "<<minOfTwo(4,10)<<endl;
    cout<<sumNos(200)<<endl;
    cout<<factorial(5)<<endl;
    return 0;
}
