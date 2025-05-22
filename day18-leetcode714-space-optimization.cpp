class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int aheadBuy = 0, aheadNotBuy = 0;

        for (int ind = n - 1; ind >= 0; ind--) {
            int currBuy = max(-prices[ind] + aheadNotBuy, aheadBuy);
            int currNotBuy = max(prices[ind] - fee + aheadBuy, aheadNotBuy);

            aheadBuy = currBuy;
            aheadNotBuy = currNotBuy;
        }

        return aheadBuy; // This is dp[0][1]
    }
};
