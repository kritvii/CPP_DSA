//find smallest or largest in array

//+infinity-->INT_MAX
//-infinity--->int MAX

#include<iostream>
using namespace std;

int main(){
    int smallest=INT_MAX;
    int largest=INT_MIN;

    int arr[]={10,-15,-1,100,-1000};
    int size=sizeof(arr)/sizeof(int);

    /*
    for(int i=0;i<size;i++){
        if (arr[i]<smallest){
            //update smallest value
            smallest=arr[i];
        }
    }
    */
    
    //direct functions
    for(int i=0;i<size;i++){ //min, max
        smallest=min(arr[i],smallest);
        largest=max(arr[i],largest);
        }
        cout<<"smallest= "<<smallest<<endl;
        cout<<"largest= "<<largest<<endl;

        return 0;
    }

