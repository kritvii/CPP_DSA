/*  LIST — DOUBLY LINKED LIST (STL container)

    list<int> l = {1, 2, 3};

    unlike vector (which is a dynamic ARRAY, backed by one
    continuous block of memory), list is a DOUBLY LINKED LIST.
    each element is its own separate node in memory, and every
    node stores:
      - the value
      - a pointer to the NEXT node
      - a pointer to the PREVIOUS node
    ("doubly" = pointers in both directions, so you can walk the
    list forwards AND backwards)

    WHY USE list INSTEAD OF vector:
    - inserting/deleting at the FRONT or in the MIDDLE is O(1) for
      list (you just relink a couple of pointers), whereas for a
      vector it's O(n) (every element after the insertion point
      has to physically shift over in memory)
    - list has NO random access — you can't do l[2] like a vector.
      to reach the 3rd element you have to walk node by node from
      the front (or back), which is O(n). vector gives O(1) random
      access via indexing because it's one contiguous block.
    - list uses more memory per element (extra space for the two
      pointers in every node) and has worse cache performance,
      since nodes can be scattered anywhere in memory instead of
      sitting next to each other like a vector's elements do.

    so: pick vector by default: pick list specifically when you need
    fast insert/delete at both ends or in the middle, and don't need
    random indexing.

    ============================================================
    FUNCTIONS COVERED IN THIS FILE
    ============================================================
    push_back()     → insert at the END
    push_front()    → insert at the FRONT
    pop_back()      → remove from the END
    pop_front()     → remove from the FRONT
    emplace_back()  → construct an element IN PLACE at the END
    emplace_front() → construct an element IN PLACE at the FRONT
*/

#include<iostream>
#include<list>
using namespace std;

int main(){

    list<int> l;   // empty doubly linked list

    // ---- push_back() ----
    // inserts a new node AFTER the current last node, becomes the new tail
    l.push_back(1);
    // list: 1

    // ---- push_front() ----
    // inserts a new node BEFORE the current first node, becomes the new head
    l.push_front(2);
    // list: 2 1

    l.push_back(3);
    // list: 2 1 3

    /*
        ---- emplace_back() vs push_back() ----
        push_back(1) takes an already-built value and COPIES (or moves) it
        into a new node at the end.

        emplace_back(1) instead CONSTRUCTS the value directly inside the
        new node, using whatever arguments you give it — skipping the
        separate "build it, then copy it in" step.

        for a simple type like int, push_back and emplace_back behave the
        same way and you won't notice a difference. the real benefit shows
        up with more complex types, e.g. a list of pairs or custom objects:
            l.emplace_back(1, 2);   → directly builds pair(1,2) in place
            l.push_back(make_pair(1, 2)); → builds a pair separately, THEN copies it in
        emplace avoids that extra temporary copy, so it's slightly more
        efficient for non-trivial types.
    */
    l.emplace_back(4);
    // list: 2 1 3 4

    l.emplace_front(5);
    // list: 5 2 1 3 4

    // ---- pop_back() ----
    // removes the LAST node. does NOT return the removed value
    // (if you need it, read it with l.back() before popping)
    l.pop_back();
    // removes 4 → list: 5 2 1 3

    // ---- pop_front() ----
    // removes the FIRST node
    l.pop_front();
    // removes 5 → list: 2 1 3

    // list doesn't support range-based indexing (no l[i]), but a
    // range-based for loop still works fine since list supports
    // iteration front-to-back via its iterators internally
    for(int val:l){
        cout<<val<<" ";   // 2 1 3
    }
    cout<<endl;

    return 0;
}