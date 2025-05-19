class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<long>> dp(n + 1, vector<long>(2, 0));

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                long profit = 0;
                if (buy == 0) {
                    profit = max(0 + dp[ind + 1][0], -prices[ind] + dp[ind + 1][1]);
                } else {
                    profit = max(0 + dp[ind + 1][1], prices[ind] + dp[ind + 1][0]);
                }
                dp[ind][buy] = profit;
            }
        }

        return dp[0][0];
    }
};
