//time complexity: O(log n to the base n) where d is the number of digits in n
#include<iostream>
using namespace std;

void printDigit(int n){
    int sum=0;
    int count=0;
    while(n!=0){
        int digit=n%10;
        cout<<digit<<endl;

        sum+=digit;
        count++;
        n=n/10;
    }
    cout<<"Sum: "<<sum<<endl;
    cout<<"Count: "<<count<<endl;
}

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    printDigit(n);

    return 0;
}