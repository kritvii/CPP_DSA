/*
STATIC VS DYNAMIC ALLOCATION

Static:
runs in compile time
fixed size
stack memory 

Dynamic:
runtime
resize is possible
heap memory 
*/

#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>vec;
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(2);

    cout<<vec.size()<<endl;//3
    cout<<vec.capacity()<<endl;//4
    


    return 0;
}