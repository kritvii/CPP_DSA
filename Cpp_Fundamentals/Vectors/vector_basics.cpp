/*
VECTOR

it is like an array but only difference is that it is dynamic(size can be changed)

STL-->standard template lib
includes vectors,queue,stack set adlso knows as STL CONTAINERS


VECTOR SYNTAX:
vector<int>vec;
vector<int>vec={1,2,3}
vector<int>vec(3,0)
*/

#include<iostream>
#include<vector> //to be used
using namespace std;

int main(){
    vector<int> vec; //size:0 no elements are stored 
   // cout<<vec[0];//-->segmentation fault:vector is empty 

    vector<int>vec1={1,2,3};//3
   // cout<<vec1[0]<<endl;

    vector<int> vec2(5,0);
    cout<<"size= "<<vec2.size()<<endl;//5

    //size of the vector:5, and value at each index:0

   // For every eleme nt in vec2, store it in val and execute the loop body.
    for(int val:vec2){ //printing the value stored in the index
       cout<<val<<endl;//0 0 0 0 0
    }

    vector<char> vec3={'a','b','c','d','e'};

    cout<<"size= "<<vec3.size()<<endl;//5
    for(char val:vec3){
        cout<<val<<endl;//a b c d e
    }
    
    return 0;

}