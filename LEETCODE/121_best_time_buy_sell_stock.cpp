// LC 121 - Best Time to Buy and Sell Stock
// Pattern : Greedy / Single Pass
// Time    : O(n)  |  Space : O(1)

// Core idea: track two things as you scan left to right —
// minimum buy price seen so far → cheapest day to have bought
// maximum profit seen so far    → best sell we could've made

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int buy    = prices[0];  // init to first price — cheapest buy so far
        int profit = 0;          // init to 0 — return 0 if no profit possible

        for(int i = 1; i < prices.size(); i++) {

            // if we sell today, would it beat our best profit?
            // prices[i] - buy is negative when prices[i] < buy
            // max() ignores it automatically — no if check needed
            profit = max(profit, prices[i] - buy);

            // update cheapest buy price seen so far
            buy = min(buy, prices[i]);

            // NOTE: profit updated BEFORE buy
            // flipping the order means buy could update to today's price
            // making profit = 0 (buying and selling on same day)
        }

        return profit;
    }
};

// DRY RUN: [7, 1, 5, 3, 6, 4]
// i=1: profit=max(0, 1-7)=0,  buy=min(7,1)=1
// i=2: profit=max(0, 5-1)=4,  buy=min(1,5)=1
// i=3: profit=max(4, 3-1)=4,  buy=min(1,3)=1
// i=4: profit=max(4, 6-1)=5,  buy=min(1,6)=1  ← answer locked
// i=5: profit=max(5, 4-1)=5,  buy=min(1,4)=1
// return 5 ✓

