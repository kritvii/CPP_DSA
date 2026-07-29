/*
    ============================================================
    COMMON VECTOR FUNCTIONS COVERED IN THIS FILE
    ============================================================
    size()      → returns how many elements are currently stored
    push_back() → adds a new element at the END of the vector
    pop_back()  → removes the element at the END of the vector
    front()     → returns the FIRST element
    back()      → returns the LAST element
    at(i)       → returns the element at index i, with BOUNDS CHECKING

    quick note on at(i) vs vec[i]:
    - vec[i] does NOT check if i is a valid index. if i is out of range,
      it's undefined behaviour (might crash, might silently give garbage).
    - vec.at(i) DOES check. if i is out of range, it throws an
      out_of_range exception instead of silently corrupting things.
    - at() is slightly slower because of this check, so in tight loops
      people often use [] once they're sure indices are valid, but at()
      is safer while learning/debugging.
*/

#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<char> vec = {'a', 'b', 'c'};   // starts with 3 elements

    // ---- size() ----
    // returns the CURRENT number of elements (not the capacity, see
    // vector_functions2.cpp for size vs capacity)
    cout << "size ="<<vec.size()<<endl;   // 3

    // ---- push_back() ----
    // adds one element to the end of the vector, increasing size by 1
    // each time. if there isn't enough allocated space (capacity), the
    // vector automatically grows its internal storage behind the scenes.
    vec.push_back('d');   // vec is now a b c d
    vec.push_back('e');   // vec is now a b c d e
    vec.push_back('f');   // vec is now a b c d e f
    cout<<"after push back size= "<<vec.size()<<endl;   // 6
    cout<<"capacity= "<<vec.capacity()<<endl;
    // capacity is the total space currently allocated, which can be
    // >= size (the vector may have grown extra room ahead of time so it
    // doesn't need to reallocate on every single push_back)

    // ---- pop_back() ----
    // removes ONE element from the end of the vector, decreasing size by 1.
    // by default, the LAST element is the one that gets deleted.
    // note: pop_back() does NOT return the removed value — if you need
    // it, read it with back() BEFORE calling pop_back().
    vec.pop_back();   // removes 'f' → vec is now a b c d e
    cout<<"after pop back size= "<<vec.size()<<endl;   // 5

    // range-based for loop to print every element left to right
    for(char val:vec){
        cout<<val<<" ";   // a b c d e
    }
    cout << endl;

    // ---- back() ----
    // returns a reference to the LAST element (does not remove it,
    // unlike pop_back which removes but doesn't return)
    cout<<"back= "<<vec.back()<<endl;    // e

    // ---- front() ----
    // returns a reference to the FIRST element
    cout<<"front= "<<vec.front()<<endl;   // a

    // ---- at(index) ----
    // returns the element at the given index, WITH bounds checking
    // vec.at(0) is the same as vec[0] here since index 0 is valid,
    // but at() would throw an exception instead of crashing silently
    // if you passed an invalid index like vec.at(100)
    cout<<"at: "<<vec.at(0)<<endl;    // a

    return 0;
}