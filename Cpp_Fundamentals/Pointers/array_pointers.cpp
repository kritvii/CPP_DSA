#include<iostream>
using namespace std;

// ARRAY POINTERS
// array name itself is a CONSTANT pointer to the first element
// you cannot change where it points — it always points to arr[0]

int main(){

    int arr[] = {1, 2, 3, 4, 5};
    // arr is stored at some base address, say 100
    // each int takes 4 bytes → arr[0]=100, arr[1]=104, arr[2]=108...

    cout << arr   << endl;   // address of first element → 100
    cout << &arr  << endl;   // address of the array itself → also 100
    cout << *arr  << endl;   // value at first element → 1

    // pointer arithmetic with arrays
    // arr+1 moves 4 bytes forward (1 int = 4 bytes)
    cout << *(arr+1) << endl;   // value at arr[1] → 2  (address 104)
    cout << *(arr+2) << endl;   // value at arr[2] → 3  (address 108)
    cout << *(arr+3) << endl;   // value at arr[3] → 4  (address 112)
    cout << *(arr+4) << endl;   // value at arr[4] → 5  (address 116)

    // arr[i] and *(arr+i) are exactly the same thing
    // arr[2] == *(arr+2) == 3

    // array pointer is CONSTANT — cannot be reassigned
    // int a = 15;
    // arr = &a;   // ERROR: array pointer is not changeable

    // using a regular pointer to traverse array
    int* ptr = arr;   // ptr points to first element
    for(int i = 0; i < 5; i++){
        cout << *(ptr+i) << " ";   // same as arr[i]
    }
    cout << endl;   // 1 2 3 4 5

    // pointer increment and decrement
    int a  = 10;
    int* p = &a;

    cout << p  << endl;   // say address 200
    p++;
    cout << p  << endl;   // 204 (+4 bytes because int = 4 bytes)
    p--;
    cout << p  << endl;   // 200 (back to original)

    // pointer comparison
    int* ptr1;
    int* ptr2;

    cout << (ptr1 < ptr2)  << endl;   // 1 if true, 0 if false
    cout << (ptr1 == ptr2) << endl;   // 1 if same address, 0 if different

    return 0;
}

// MEMORY PICTURE: int arr[] = {1,2,3,4,5}
// arr[0]=1 at 100
// arr[1]=2 at 104
// arr[2]=3 at 108
// arr[3]=4 at 112
// arr[4]=5 at 116

// KEY RULES:
// arr+i   → moves i*4 bytes forward (for int array)
// *(arr+i) == arr[i]
// arr is constant → cannot be reassigned
// regular int* ptr = arr → ptr CAN be reassigned