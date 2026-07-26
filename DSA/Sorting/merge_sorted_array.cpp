#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    int p1 = m - 1;      // last real element of nums1
    int p2 = n - 1;      // last element of nums2
    int p3 = m + n - 1;  // last position to fill in nums1

    // compare from back — place larger element at p3
    while(p1 >= 0 && p2 >= 0) {
        if(nums1[p1] > nums2[p2]) {
            nums1[p3] = nums1[p1];  // nums1 element is larger
            p1--;
        } else {
            nums1[p3] = nums2[p2];  // nums2 element is larger or equal
            p2--;
        }
        p3--;  // always move fill position back
    }

    // copy leftover nums2 elements into nums1
    // WHY only p2 loop and not p1?
    // p1 leftover → already sitting in nums1 in correct place → do nothing
    // p2 leftover → sitting in separate nums2 → must copy into nums1
    while(p2 >= 0) {
        nums1[p3] = nums2[p2];
        p2--;
        p3--;
    }
}

int main() {

    // test case 1 — standard merge — expected: [1, 2, 2, 3, 5, 6]
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    merge(nums1, 3, nums2, 3);
    cout << "Test 1: ";
    for(int x : nums1) cout << x << " ";
    cout << endl;

    // test case 2 — p2 runs out first (nums1 has larger elements)
    // main loop ends with p2<0, p1 still has elements
    // p1 leftovers already in place → no second loop needed
    // expected: [1, 2, 3]
    vector<int> nums3 = {1, 0, 0};
    vector<int> nums4 = {2, 3};
    merge(nums3, 1, nums4, 2);
    cout << "Test 2 (p2 runs out): ";
    for(int x : nums3) cout << x << " ";
    cout << endl;

    // test case 3 — p1 runs out first (nums2 has larger elements)
    // main loop ends with p1<0, p2 still has elements
    // second while(p2>=0) kicks in to copy remaining nums2 into nums1
    // expected: [1, 2, 3]
    vector<int> nums5 = {3, 0, 0};
    vector<int> nums6 = {1, 2};
    merge(nums5, 1, nums6, 2);
    cout << "Test 3 (p1 runs out): ";
    for(int x : nums5) cout << x << " ";
    cout << endl;

    // test case 4 — nums2 is empty — expected: [1]
    vector<int> nums7 = {1};
    vector<int> nums8 = {};
    merge(nums7, 1, nums8, 0);
    cout << "Test 4 (empty nums2): ";
    for(int x : nums7) cout << x << " ";
    cout << endl;

    // test case 5 — nums1 is empty — expected: [1]
    vector<int> nums9  = {0};
    vector<int> nums10 = {1};
    merge(nums9, 0, nums10, 1);
    cout << "Test 5 (empty nums1): ";
    for(int x : nums9) cout << x << " ";
    cout << endl;

    return 0;
}

// DRY RUN: nums1=[1,2,3,0,0,0] m=3, nums2=[2,5,6] n=3
// p1=2, p2=2, p3=5
// nums1[2]=3 vs nums2[2]=6 → 6 wins → nums1[5]=6, p2=1, p3=4
// nums1[2]=3 vs nums2[1]=5 → 5 wins → nums1[4]=5, p2=0, p3=3
// nums1[2]=3 vs nums2[0]=2 → 3 wins → nums1[3]=3, p1=1, p3=2
// nums1[1]=2 vs nums2[0]=2 → equal  → nums1[2]=2, p2=-1, p3=1
// p2 < 0 → loop ends → nums1[0,1] already in place ✓
// Final: [1, 2, 2, 3, 5, 6] ✓

// WHY SECOND WHILE LOOP?
// main loop stops when EITHER p1 or p2 runs out
// scenario 1: p2 runs out first → p1 leftovers already in nums1 → done
// scenario 2: p1 runs out first → p2 leftovers in nums2 → must copy!
// example: nums1=[3,0,0] nums2=[1,2]
//   iter1: 3>2 → nums1[2]=3, p1=-1 → main loop ends
//   second loop: nums1[1]=2, nums1[0]=1 → [1,2,3] ✓

// TRAPS:
// ❌ merging from front → causes shifting → O(n²)
// ✅ merge from back → fill empty slots directly → O(m+n)
// ❌ forgetting p3-- in leftover loop → overwrites same slot
// ❌ forgetting while(p2>=0) → leftover nums2 not copied
// ✅ no need for while(p1>=0) → remaining nums1 already in place