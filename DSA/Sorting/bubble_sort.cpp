//BUBBLE SORT 
#include<iostream>
using namespace std;

// Time Complexity:
//   Best case:    O(n)    -> array already sorted, isSwap triggers early return after 1 pass
//   Average case: O(n^2)  -> elements in random order
//   Worst case:   O(n^2)  -> array sorted in reverse order, every pass requires swaps
// Space Complexity: O(1)  -> sorts in-place, only constant extra variables used


void bubbleSort(int arr[], int n){ 
    // Note: arr[] decays to a pointer here — it points to the SAME memory
    // as the array in main(). No copy is made, so any changes made below
    // directly modify main()'s original array. That's why this function
    // is void and doesn't need to return anything.

    for(int i=0; i<n-1; i++){ // no of iterations (passes)
        bool isSwap = false; // reset flag at the start of every pass

        for(int j=0; j<n-i-1; j++){ // no of comparisons in this pass
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]); // swap out-of-order adjacent elements
                isSwap = true; // mark that a swap happened this pass
            }
        }

        // If no swaps happened, array is already sorted — exit early
        if(!isSwap) return; 

    }
}

int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr, n); // sorts arr in-place; no return value needed

    cout << "Sorted array: \n";
    for (int i=0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
/*
Dry Run
Initial array: {64, 34, 25, 12, 22, 11, 90} , n = 7

i=0 (j: 0 to 5): isSwap=false initially
    j=0: 64>34 -> swap -> {34,64,25,12,22,11,90}
    j=1: 64>25 -> swap -> {34,25,64,12,22,11,90}
    j=2: 64>12 -> swap -> {34,25,12,64,22,11,90}
    j=3: 64>22 -> swap -> {34,25,12,22,64,11,90}
    j=4: 64>11 -> swap -> {34,25,12,22,11,64,90}
    j=5: 64>90? No
    isSwap=true -> continue -> array: {34,25,12,22,11,64,90}

i=1 (j: 0 to 4):
    j=0: 34>25 -> swap -> {25,34,12,22,11,64,90}
    j=1: 34>12 -> swap -> {25,12,34,22,11,64,90}
    j=2: 34>22 -> swap -> {25,12,22,34,11,64,90}
    j=3: 34>11 -> swap -> {25,12,22,11,34,64,90}
    j=4: 34>64? No
    isSwap=true -> continue -> array: {25,12,22,11,34,64,90}

i=2 (j: 0 to 3):
    j=0: 25>12 -> swap -> {12,25,22,11,34,64,90}
    j=1: 25>22 -> swap -> {12,22,25,11,34,64,90}
    j=2: 25>11 -> swap -> {12,22,11,25,34,64,90}
    j=3: 25>34? No
    isSwap=true -> continue -> array: {12,22,11,25,34,64,90}

i=3 (j: 0 to 2):
    j=0: 12>22? No
    j=1: 22>11 -> swap -> {12,11,22,25,34,64,90}
    j=2: 22>25? No
    isSwap=true -> continue -> array: {12,11,22,25,34,64,90}

i=4 (j: 0 to 1):
    j=0: 12>11 -> swap -> {11,12,22,25,34,64,90}
    j=1: 12>22? No
    isSwap=true -> continue -> array: {11,12,22,25,34,64,90}

i=5 (j: 0 to 0):
    j=0: 11>12? No
    isSwap=false -> return (early exit, array already sorted)

Final sorted array: {11, 12, 22, 25, 34, 64, 90}
*/