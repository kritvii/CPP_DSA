//binary to decimal

#include<iostream>
using namespace std;

int dec_to_bin(int dec){
    int ans=0;//binary no
    int pow=1; //10**0=1

    while(dec>0){
        int rem=dec%2;
        dec/=2;

        ans+=(rem*pow);
        pow*=10;
    }
    return ans;
}

int main(){
    int decimal_no;
    cout<<"Enter decimal no: ";
    cin>>decimal_no;
    cout<<"Binary of "<<decimal_no<<" is "<<dec_to_bin(decimal_no)<<endl;
    return 0;
}