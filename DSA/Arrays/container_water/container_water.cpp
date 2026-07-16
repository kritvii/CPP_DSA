/*
Problem: Container With Most Water
Platform: LeetCode 11
Topic: Arrays, Two Pointers
Approach: Two Pointer Technique

Time Complexity: O(n)
Space Complexity: O(1)
*/
#include <iostream>
#include <vector>
#include <algorithm>  // for min(), max()
using namespace std;

int maxArea(vector<int>& height) {

    int left     = 0;
    int right    = height.size() - 1;
    int maxWater = 0;

    while(left < right) {

        // width = gap between the two pointers
        int currWidth = right - left;

        // height is capped by the shorter line
        int ht = min(height[left], height[right]);

        // area of water this container holds
        int area = currWidth * ht;

        // update best answer seen so far
        maxWater = max(maxWater, area);

        // move the shorter pointer inward
        if(height[left] < height[right])
            left++;
        else
            right--;
    }

    return maxWater;
}

int main() {

    // test case 1 — expected: 49
    vector<int> h1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Test 1: " << maxArea(h1) << endl;

    // test case 3 — all same height — expected: 4
    vector<int> h3 = {4, 4, 4, 4, 4};
    cout << "Test 3: " << maxArea(h3) << endl;

    // test case 4 — increasing heights — expected: 8
    vector<int> h4 = {1, 2, 3, 4, 5};
    cout << "Test 4: " << maxArea(h4) << endl;

    return 0;
}

// DRY RUN: [1, 8, 6, 2, 5, 4, 8, 3, 7]
// L=0(h=1), R=8(h=7) → area=1×8=8,   move L
// L=1(h=8), R=8(h=7) → area=7×7=49,  move R  ← answer locked
// L=1(h=8), R=7(h=3) → area=3×6=18,  move R
// L=1(h=8), R=6(h=8) → area=8×5=40,  move R
// ...
// Answer: 49 ✓

// TRAPS:
// ❌ naming variable 'height' → shadows the parameter
// ❌ forgetting to move pointer → infinite loop
// ✅ always move the shorter pointer inward