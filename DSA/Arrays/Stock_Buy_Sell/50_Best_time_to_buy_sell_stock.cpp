#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices) {  // pass by reference — no copy made
    int n      = prices.size();
    int buy    = prices[0];  // track the minimum price seen so far
    int profit = 0;          // init to 0 — handles no-profit case automatically

    // scan left to right, tracking min buy price and max profit
    for(int i = 1; i < n; i++) {
         
        if(prices[i] > buy) { //if not needed
        // calculate profit if we sell today, lock in best seen so far
        profit = max(profit, prices[i] - buy);
        }
        // update minimum buy price seen so far
        buy = min(buy, prices[i]);

        // NOTE: update profit BEFORE buy
        // if flipped, buy might update to today's price
        // and profit would be 0 (buying and selling same day)
    }

    return profit;
}
int main(){
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout<<"MAX PROFIT : "<<maxProfit(prices)<<endl;
    return 0;
}

/*

prices = [7, 1, 5, 3, 6, 4],  buy = 7,  profit = 0

i=1: prices[1]=1  < buy  → skip profit,  buy = min(7,1) = 1
i=2: prices[2]=5  > buy  → profit = max(5-1, 0) = 4,   buy = 1
i=3: prices[3]=3  > buy  → profit = max(3-1, 4) = 4,   buy = 1
i=4: prices[4]=6  > buy  → profit = max(6-1, 4) = 5,   buy = 1
i=5: prices[5]=4  > buy  → profit = max(4-1, 5) = 5,   buy = 1

return 5 ✓
*/