#include <iostream>
using namespace std;

/*
type 1:
int main(){

    char ch;
    cout<<"enter char: ";
    cin>>ch;

    if(ch>='a' && ch<='z'){
        cout<<"character is in lower case\n";
    }else{
        cout<<"character is in uppercase\n";
    }
    return 0;
}

*/

//using ascii value 
//'a'->97  ,  'A'->65
int main(){

    char ch;
    cout<<"enter char: ";
    cin>>ch;

    if(ch>=65 && ch<=90){  
        //implicit type conversion(comaparing character with integer )
        cout<<"uppercase\n";
    }else{
        cout<<"lowercase\n";
    }
    return 0;
  
}

