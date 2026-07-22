//SELECTION SORT
#include<iostream>
using namespace std;

// Time Complexity:
//   Best case:    O(n^2)  -> always scans full unsorted part, no early exit possible
//   Average case: O(n^2)
//   Worst case:   O(n^2)
// Space Complexity: O(1)  -> sorts in-place, only constant extra variables used

void selectionSort(int arr[], int n){

    for(int i=0; i<n-1; i++){ // no of iterations = n-1 (last element auto-sorted)
        int minIndex = i; // assume the min is the first element of unsorted part

        for(int j=i+1; j<n; j++){ // find the index of the minimum element
            if (arr[j] < arr[minIndex]){
                minIndex = j; // update minIndex whenever a smaller element is found
            }
        }
        // Swap only if a smaller element was found elsewhere.
        // This avoids an unnecessary self-swap.
        if (minIndex != i){
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    cout << "Sorted Array: \n";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
Dry Run
Initial array: {64, 34, 25, 12, 22, 11, 90} , n = 7

i = 0: minIndex = 0 (value 64)
    j=1: 34 < 64 -> minIndex = 1
    j=2: 25 < 34 -> minIndex = 2
    j=3: 12 < 25 -> minIndex = 3
    j=4: 22 < 12? No
    j=5: 11 < 12 -> minIndex = 5
    j=6: 90 < 11? No
    Swap arr[0] and arr[5] -> {11, 34, 25, 12, 22, 64, 90}

i = 1: minIndex = 1 (value 34)
    j=2: 25 < 34 -> minIndex = 2
    j=3: 12 < 25 -> minIndex = 3
    j=4: 22 < 12? No
    j=5: 64 < 12? No
    j=6: 90 < 12? No
    Swap arr[1] and arr[3] -> {11, 12, 25, 34, 22, 64, 90}

i = 2: minIndex = 2 (value 25)
    j=3: 34 < 25? No
    j=4: 22 < 25 -> minIndex = 4
    j=5: 64 < 22? No
    j=6: 90 < 22? No
    Swap arr[2] and arr[4] -> {11, 12, 22, 34, 25, 64, 90}

i = 3: minIndex = 3 (value 34)
    j=4: 25 < 34 -> minIndex = 4
    j=5: 64 < 25? No
    j=6: 90 < 25? No
    Swap arr[3] and arr[4] -> {11, 12, 22, 25, 34, 64, 90}

i = 4: minIndex = 4 (value 34)
    j=5: 64 < 34? No
    j=6: 90 < 34? No
    minIndex == i -> skip swap (already in correct position) -> {11, 12, 22, 25, 34, 64, 90}

i = 5: minIndex = 5 (value 64)
    j=6: 90 < 64? No
    minIndex == i -> skip swap (already in correct position) -> {11, 12, 22, 25, 34, 64, 90}

Loop ends (i goes only up to n-2 = 5)
Final sorted array: {11, 12, 22, 25, 34, 64, 90}
*/