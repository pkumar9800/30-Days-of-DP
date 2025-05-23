class Solution {
private:
int fun(vector<int>& prices, int n, int ind, int buy, int cap, vector<vector<vector<int>>>& dp) {
    if (ind == n || cap == 0)
        return 0;

    if (dp[ind][buy][cap] != -1)
        return dp[ind][buy][cap];

    int profit;

    if (buy == 0) { 
        profit = max(0 + fun(prices, n, ind + 1, 0, cap, dp),
                     -prices[ind] + fun(prices, n, ind + 1, 1, cap, dp));
    }

    if (buy == 1) {
        profit = max(0 + fun(prices, n, ind + 1, 1, cap, dp),
                     prices[ind] + fun(prices, n, ind + 1, 0, cap - 1, dp));
    }

    return dp[ind][buy][cap] = profit;
}
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return fun(prices, n, 0, 0, 2, dp);
    }
};