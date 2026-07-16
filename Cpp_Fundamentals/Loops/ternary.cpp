/*TERNARY STAEMENTS
   
condition?str1:str2;
condition?true:false;

eg:n>=0?"pos":"neg";
*/

#include <iostream>;
using namespace std;

int main(){

    int no;
    cout<<"enter number : ";
    cin>>no;

    cout<<(no>=0?"positive":"negative")<<endl;

    return 0;
}
