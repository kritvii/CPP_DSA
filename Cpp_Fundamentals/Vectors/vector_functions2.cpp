/*
    ============================================================
    STATIC VS DYNAMIC ALLOCATION
    ============================================================
    STATIC (normal array, e.g. int arr[5]):
    - size is decided at COMPILE time — you must know the size in
      advance, and it can never change while the program runs
    - lives on STACK memory — fast, but limited in size, and gets
      cleaned up automatically when the function it's in returns
    - example: int arr[5];  → arr can only ever hold exactly 5 ints

    DYNAMIC (vector):
    - size is decided at RUNTIME — can be based on user input,
      computed values, etc., and can change as the program runs
    - resizing is possible — push_back/pop_back/resize() etc. let the
      vector grow or shrink whenever needed
    - lives on HEAP memory — more flexible, but slightly slower to
      access than stack memory, and has to be managed (vector handles
      this memory management for you automatically, unlike raw
      pointers/new[] where you'd have to manually delete[] it)

    ============================================================
    SIZE vs CAPACITY (the important part of this file)
    ============================================================
    size()     → the number of elements ACTUALLY stored right now
    capacity() → the amount of space ALREADY ALLOCATED in memory
                 (this can be greater than or equal to size, never less)

    WHY capacity can be bigger than size:
    reallocating memory (asking the OS/heap for a new, bigger block,
    then copying every old element into it) is a RELATIVELY EXPENSIVE
    operation. if a vector reallocated on every single push_back, that
    would be extremely slow for large vectors.

    so instead, when a vector runs out of room, it doesn't just grow by
    1 slot — it grows by a MULTIPLE of its current capacity (commonly
    doubling it, though the exact factor depends on the STL
    implementation/compiler). that extra unused room means the next
    few push_back() calls are "free" (no reallocation needed) until
    capacity is exhausted again.

    this is why you'll often see something like:
        size = 3
        capacity = 4
    the vector already grew ahead of actual need, anticipating more
    elements might get pushed in soon.

    NOTE: don't memorize exact capacity numbers as some fixed rule —
    they depend on the compiler/STL implementation you're using.
    what matters for interviews/understanding is WHY capacity >= size,
    and that this growth strategy is what makes push_back() run in
    "amortized O(1)" time on average, even though occasional individual
    push_back calls (the ones that trigger reallocation) are O(n).
*/

#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> vec;      // empty vector, size=0, capacity=0 initially

    vec.push_back(0);     // size becomes 1, vector allocates room as needed
    vec.push_back(1);     // size becomes 2
    vec.push_back(2);     // size becomes 3

    cout<<vec.size()<<endl;       // 3 → exactly how many elements we pushed
    cout<<vec.capacity()<<endl;   // >= 3, e.g. 4 → vector grew ahead of need
                                    // so the NEXT push_back (making size=4)
                                    // won't need to reallocate at all

    return 0;
}