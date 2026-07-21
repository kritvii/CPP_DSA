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