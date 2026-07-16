#include<iostream>
using namespace std;

int bin_to_dec(int bin){
    int ans=0, pow=1;

    while(bin>0){
        int rem=bin%10;
        ans+=rem*pow;

        //update
        bin/=10;
        pow*=2;
    }
    return ans;
}

int main(){
    int binary;
    cout<<"enter binary no: ";
    cin>>binary;
    cout<<bin_to_dec(binary);
    return 0;
}