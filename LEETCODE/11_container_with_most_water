// LC 11 - Container With Most Water
// Pattern : Two Pointers
// Time    : O(n)  |  Space : O(1)

// Core idea: start with widest container (L=0, R=end)
// water = min(height[L], height[R]) × (R - L)
// move the SHORTER pointer inward each time —
// moving the taller side only reduces width with no height gain

class Solution {
public:
    int maxArea(vector<int>& height) {

        int left     = 0;
        int right    = height.size() - 1;
        int maxWater = 0;

        while(left < right) {

            // width = gap between the two pointers
            int currWidth = right - left;

            // height is capped by the shorter line
            // taller line overflows — water spills out
            int ht = min(height[left], height[right]);

            // area of water this container holds
            int area = currWidth * ht;

            // update best answer seen so far
            maxWater = max(maxWater, area);

            // move the shorter pointer inward
            // keeping the shorter side gains nothing —
            // width decreases AND height stays capped
            if(height[left] < height[right])
                left++;
            else
                right--;
        }

        return maxWater;
    }
};

// DRY RUN: [1, 8, 6, 2, 5, 4, 8, 3, 7]
// L=0(h=1), R=8(h=7) → area=1×8=8,   move L (shorter)
// L=1(h=8), R=8(h=7) → area=7×7=49,  move R (shorter)
// L=1(h=8), R=7(h=3) → area=3×6=18,  move R
// L=1(h=8), R=6(h=8) → area=8×5=40,  move R
// L=1(h=8), R=5(h=4) → area=4×4=16,  move R
// L=1(h=8), R=4(h=5) → area=5×3=15,  move R
// L=1(h=8), R=3(h=2) → area=2×2=4,   move R
// L=1(h=8), R=2(h=6) → area=6×1=6,   move R
// L=1, R=1 → loop ends
// Answer: 49 ✓

// NOTE: 
// ✅ always move the shorter pointer, not the taller one