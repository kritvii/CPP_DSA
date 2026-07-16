#include<iostream>
using namespace std;

// POINTERS — BASICS
// a pointer is a variable that stores the memory address of another variable
// addresses are stored in hexadecimal format (0x7ff...)
// every run gives a different address — OS decides where to store variables

int main(){

    int a = 5;
    // 'a' is stored somewhere in memory, say address 100

    // & is the "address-of" operator
    // &a = give me the memory address where 'a' lives
    cout << "Address of a: " << &a << endl;   // prints 0x7ff... (changes every run)

    // * is the "dereference" operator
    // *(&a) = go to that address and read what's there
    cout << "Value at address of a: " << *(&a) << endl;  // prints 5

    // declaring a pointer
    // int* ptr means ptr is a variable that stores address of an int
    int* ptr = &a;   // ptr stores address of a → ptr = 100

    cout << "ptr (address of a): " << ptr  << endl;  // 100
    cout << "*ptr (value at ptr): " << *ptr << endl;  // 5

    // pointer to pointer
    // int** ptr2 stores the address of a pointer
    int** ptr2 = &ptr;  // ptr2 stores address of ptr → ptr2 = 300

    cout << "ptr2 (address of ptr): "    << ptr2  << endl;  // 300
    cout << "*ptr2 (value at ptr2): "    << *ptr2 << endl;  // 100 (address of a)
    cout << "**ptr2 (value at *ptr2): "  << **ptr2 << endl; // 5

    // NULL pointer
    // a pointer that doesn't point to any location
    int* ptr3;           // uninitialized → garbage value (dangerous!)
    int* ptr4 = NULL;    // NULL pointer → points to 0x0 (safe)

    cout << "uninitialized ptr: " << ptr3 << endl;  // garbage
    cout << "NULL ptr: "         << ptr4 << endl;  // 0x0

    // NEVER dereference a NULL pointer → segmentation fault
    // *ptr4 → crash!

    return 0;
}

// MEMORY PICTURE:
// variable   value   address
//    a     →   5   →  100
//    ptr   →  100  →  300     (ptr stores address of a)
//    ptr2  →  300  →  500     (ptr2 stores address of ptr)

// OPERATORS:
// &  → address-of  → &a   gives 100
// *  → dereference → *ptr gives 5