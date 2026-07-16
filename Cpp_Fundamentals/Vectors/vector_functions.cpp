/*
size
push_back
pop_back
front
back 
at
*/

#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<char>vec={'a','b','c'};
    //size
    cout<<"size ="<<vec.size()<<endl;//3
    //push
    vec.push_back('d');
    vec.push_back('e');
    vec.push_back('f');
    cout<<"after push back size= "<<vec.size()<<endl;//6
    cout<<"capacity= "<<vec.capacity()<<endl;//4
    //pop
    vec.pop_back();
    //by default last element is deleted
    cout<<"after pop back size= "<<vec.size()<<endl;//5
    
    for(char val:vec){
        cout<<val<<" ";//a b c d e 
    }

    //back:last element
    cout<<"back= "<<vec.back()<<endl;//e
    //front:first element
    cout<<"front= "<<vec.front()<<endl;//a
    //at: @index value
    cout<<"at: "<<vec.at(0)<<endl;//a
    return 0;
}