#include<iostream>
using namespace std;

// PASS BY VALUE vs PASS BY REFERENCE
// pass by value     → function gets a COPY → original unchanged
// pass by reference → function gets ADDRESS → original changes

// METHOD 1: pass by value
// a copy of the argument is made inside the function
// changes inside function don't affect original variable
void changeA_byValue(int a) {
    a = 20;   // changes local copy only
}

// METHOD 2: pass by reference using pointers
// address of the variable is passed
// function uses *ptr to go to that address and change the value
// original variable gets modified
void changeA_byPointer(int* ptr) {
    *ptr = 20;   // go to address and change value there
}

// METHOD 3: pass by reference using alias (&)
// alias = another name for the same variable
// no copy made, no address needed — directly works on original
void changeA_byAlias(int& ref) {
    ref = 20;   // ref is just another name for the original variable
}

int main(){

    // pass by value — original unchanged
    int a = 10;
    changeA_byValue(a);
    cout << "After pass by value: " << a << endl;    // 10 (unchanged)

    // pass by reference using pointer — original changes
    int b = 10;
    changeA_byPointer(&b);   // pass address of b
    cout << "After pass by pointer: " << b << endl;  // 20 (changed)

    // pass by reference using alias — original changes
    int c = 10;
    changeA_byAlias(c);      // no & needed here, just pass c
    cout << "After pass by alias: " << c << endl;    // 20 (changed)

    return 0;
}

// SUMMARY:
// pass by value   → void f(int a)    → copy made → original safe
// pass by pointer → void f(int* ptr) → address passed → original changes
// pass by alias   → void f(int& ref) → no copy, no address → original changes

// WHEN TO USE:
// pass by value   → when you don't want to modify original
// pass by pointer → when you want to modify original (C style)
// pass by alias   → when you want to modify original (C++ style, cleaner)