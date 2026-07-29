#include<iostream>
#include<vector>
#include<algorithm>   // needed here because we use sort() later in this file
using namespace std;

/*
    ============================================================
    VECTORS — WHAT AND WHY
    ============================================================
    A vector is a DYNAMIC ARRAY.
    - "dynamic" means its size can grow or shrink while the program is
      running (a normal array like int arr[5] is stuck at size 5 forever,
      decided at compile time).
    - vector is part of the STL (Standard Template Library) — a bunch of
      ready-made, well-tested data structures/containers so we don't have
      to write our own dynamic array, stack, queue etc. from scratch.
    - other STL containers you'll run into: queue, stack, set, map, etc.
      they all follow similar ideas (begin/end, size, push/pop functions).

    ============================================================
    WAYS TO DECLARE / INITIALIZE A VECTOR
    ============================================================
    vector<int> vec;              → empty vector, size = 0, no elements yet
    vector<int> vec = {1,2,3};    → initialized directly with these values, size = 3
    vector<int> vec(5, 0);        → size 5, EVERY element set to 0
    vector<int> vec(10, -1);      → size 10, EVERY element set to -1
    vector<int> vec(5);           → size 5, elements default to 0 (int default is 0)

    the general pattern for vector(n, val) is:
        vector<type> name(count, value_to_fill_with)
    if you skip "value_to_fill_with", it just uses the type's default
    (0 for int, '\0'/garbage-safe for char etc. depending on type)
*/

int main(){

    // ---- empty vector ----
    vector<int> vec;   // declares a vector of ints, currently holding 0 elements
    // cout << vec[0];  → DON'T do this. vec has no elements, so accessing
    // index 0 reads memory that doesn't belong to any element yet.
    // this is undefined behaviour and commonly causes a segmentation fault.

    // ---- vector initialized with a list of values ----
    vector<int> vec1 = {1, 2, 3};
    // this is called "list initialization" — same idea as initializing an
    // array with {1,2,3}, but here the vector automatically figures out
    // its own size (3) from how many values you gave it.

    // ---- vec2(5, 0): size 5, every element = 0 ----
    // the first argument (5) is the SIZE/count of elements to create.
    // the second argument (0) is the VALUE every one of those elements
    // should be filled with.
    vector<int> vec2(5, 0);
    cout << "size= " << vec2.size() << endl;  // size() returns current element count → 5
    for(int val : vec2) cout << val << " ";   // range-based for loop, prints each element
    cout << endl;                              // expected output: 0 0 0 0 0

    // ---- vec3(10, -1): size 10, every element = -1 ----
    // this exact pattern (n, -1) shows up CONSTANTLY in DSA problems:
    //   • Dynamic Programming (tabulation): dp[] or dp[][] initialized to -1
    //     so you can check "if dp[i] == -1, it hasn't been computed yet,
    //     go compute it; otherwise just return the cached value"
    //   • visited arrays in graph traversal (BFS/DFS): initialized to 0,
    //     meaning "not visited yet" — you flip to 1 once you visit a node
    //   • distance arrays in shortest-path algorithms (like Dijkstra/BFS):
    //     initialized to INT_MAX (or some large number), meaning
    //     "not reached yet" — you update it as you find shorter paths
    // so whenever you see vector<int> dp(n, -1) in someone's code, this is why.
    vector<int> vec3(10, -1);
    cout << "size= " << vec3.size() << endl;  // 10
    for(int val : vec3) cout << val << " ";   // -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
    cout << endl;

    // ---- vec4(5): size 5, all values default to 0 ----
    // when you don't pass a fill value, vector uses the TYPE's default
    // constructor for each element. for int, that default is 0.
    vector<int> vec4(5);
    cout << "size= " << vec4.size() << endl;  // 5
    for(int val : vec4) cout << val << " ";   // 0 0 0 0 0
    cout << endl;

    // ---- vector of a different type (char) ----
    // vectors are templated, meaning they work with ANY type:
    // vector<int>, vector<char>, vector<string>, vector<vector<int>>
    // (a vector of vectors, i.e. a 2D dynamic array), etc.
    vector<char> vec5 = {'a', 'b', 'c', 'd', 'e'};
    cout << "size= " << vec5.size() << endl;  // 5
    for(char val : vec5) cout << val << " ";  // a b c d e
    cout << endl;

    /*
        ============================================================
        COPYING A VECTOR (deep copy, fully independent)
        ============================================================
        vector<int> backup(original);

        this creates a BRAND NEW vector called "backup" and copies every
        element of "original" into it. after this line, "backup" and
        "original" are two completely separate vectors in memory —
        changing one does NOT affect the other.

        this is different from doing something like a pointer/reference,
        where both names would point to the SAME underlying data.
        with vector's copy constructor, you truly get two independent
        copies of the data.
    */
    vector<int> original = {3, 1, 4, 1, 5};
    vector<int> backup(original);   // backup now = [3, 1, 4, 1, 5], independent copy

    // sort(begin_iterator, end_iterator) sorts the range IN PLACE
    // (i.e. it rearranges the actual elements of "original" itself,
    // it does not return a new sorted vector)
    sort(original.begin(), original.end());
    // after this line:
    // original = [1, 1, 3, 4, 5]  ← got rearranged in ascending order
    // backup   = [3, 1, 4, 1, 5]  ← stays exactly as it was, since it's a
    //                                separate copy that sort() never touched

    cout << "ORIGINAL: ";
    for(int val : original) cout << val << " ";  // 1 1 3 4 5
    cout << endl;
    cout << "BACKUP: ";
    for(int val : backup) cout << val << " ";     // 3 1 4 1 5
    cout << endl;

    return 0;
}

/*
    ============================================================
    QUICK REFERENCE — ALL INITIALIZATION WAYS
    ============================================================
    vector<int> v1;              → empty, size=0
    vector<int> v2 = {1,2,3};    → size=3, values=[1,2,3]
    vector<int> v3(5, 0);        → size=5, all 0s
    vector<int> v4(10, -1);      → size=10, all -1s  ← very common in DSA
    vector<int> v5(5);           → size=5, all 0s by default
*/