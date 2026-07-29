// ============================================================
// VECTOR ITERATORS
// ============================================================
// an iterator is basically a POINTER to an element of the vector.
// it "points at" a position, and you use *(it) to get the value
// stored at that position — very similar to how you'd dereference
// a raw pointer.
//
// the 2 main iterators every vector has:
//   vec.begin()  → points to the FIRST element
//   vec.end()    → points to ONE PAST the last element
//                  (this is NOT a valid element — it's a marker
//                  used to know where the vector "ends")
//
// there are also reverse iterators for traversing backwards:
//   vec.rbegin() → points to the LAST element
//   vec.rend()   → points to ONE BEFORE the first element

#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> vec={1,2,3,4,5};

    // *(vec.begin()) dereferences the begin() iterator → gives the
    // value stored at the first position
    cout<<"vec.begin()= "<<*(vec.begin())<<endl;   // 1

    // *(vec.end()) is DANGEROUS — end() points to one PAST the last
    // valid element, so dereferencing it directly reads memory that
    // isn't actually a valid element. this is undefined behaviour —
    // it might print garbage, might crash, might "accidentally" work.
    // NEVER dereference end() directly in real code.
    cout<<"vec.end()= "<<*(vec.end())<<endl;   // garbage value (undefined behaviour)

    // vec.end() - 1 steps ONE position BACK from end(), landing exactly
    // on the LAST valid element. this is a safe and common way to grab
    // the last element using iterators.
    cout<<"vec.end()-1= "<<*(vec.end()-1)<<endl;   // 5

    // ------------------------------------------------------------
    // FORWARD TRAVERSAL using an explicit iterator
    // ------------------------------------------------------------
    // vector<int>::iterator declares a variable "it" whose type is
    // "an iterator over a vector<int>" — it starts at begin() and we
    // manually move it forward one step at a time with it++, stopping
    // the moment it becomes equal to end() (since end() itself isn't
    // a real element, we stop BEFORE processing it, hence it != end()
    // rather than it <= end())
    vector<int>::iterator it;
    for(it=vec.begin();it!=vec.end();it++){
        cout<<*(it)<<" ";   // 1 2 3 4 5
    }
    cout<<endl;

    // ------------------------------------------------------------
    // BACKWARD / REVERSE TRAVERSAL using rbegin()/rend()
    // ------------------------------------------------------------
    // "auto" lets the compiler figure out the iterator type for us
    // (saves us from writing out vector<int>::reverse_iterator by hand)
    // rbegin() starts at the LAST element, and each it++ here actually
    // moves BACKWARDS through the vector (that's the whole point of a
    // reverse_iterator — incrementing it moves opposite to normal),
    // stopping once it reaches rend() (one before the first element)
    for(auto it=vec.rbegin();it!=vec.rend();it++){
        cout<<*(it)<<" ";   // 5 4 3 2 1
    }
    cout<<endl;

    return 0;
}