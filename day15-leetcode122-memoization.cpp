class Solution {
private:
long fun(vector<int>& prices, int ind, int buy, int n, vector<vector<long>> &dp) {
    if (ind == n) {
        return 0;
    }

    if (dp[ind][buy] != -1) {
        return dp[ind][buy];
    }

    long profit = 0;

    if (buy == 0) { 
        profit = max(0 + fun(prices, ind + 1, 0, n, dp), -prices[ind] + fun(prices, ind + 1, 1, n, dp));
    }

    if (buy == 1) { 
        profit = max(0 + fun(prices, ind + 1, 1, n, dp), prices[ind] + fun(prices, ind + 1, 0, n, dp));
    }

    return dp[ind][buy] = profit;
}
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<long>> dp(n, vector<long>(2, -1));

        if (n == 0) {
            return 0;
        }

        long ans = fun(prices, 0, 0, n, dp);
        return ans;
    }
};