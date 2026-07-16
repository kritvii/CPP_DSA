#include<iostream>
using namespace std;

/*
1 1 1 1      space=0 ,num=4
  2 2 2      space=1 ,num=3
    3 3      space=2 ,num=2
      4      space=3 ,num=1

i=no of spaces
num=n-i

loop 1:                   loop 2:
for spaces---->           for numbers---->
for(j=0;j<i;j++){         for(j=0;j<n-i;j++)
cout<<" "                 cout<<(i+1);
}

for this pattern space=
*/
int main(){
    int n=4;
    for(int i=0;i<n;i++ ){//no of lines

        //spaces
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        
        //nums
        for(int j=0;j<n-i;j++){
            cout<<(i+1);
        }
        cout<<endl;

    }
    return 0;
}