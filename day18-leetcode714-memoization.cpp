class Solution {
public:
    int solve(int ind, int buy, vector<int>& prices, int fee, vector<vector<int>>& dp) {
        if (ind == prices.size()) return 0;
        if (dp[ind][buy] != -1) return dp[ind][buy];

        int profit = 0;
        if (buy) {
            int b = -prices[ind] + solve(ind + 1, 0, prices, fee, dp);
            int nb = solve(ind + 1, 1, prices, fee, dp);
            profit = max(b, nb);
        } else {
            int s = prices[ind] - fee + solve(ind + 1, 1, prices, fee, dp);
            int ns = solve(ind + 1, 0, prices, fee, dp);
            profit = max(s, ns);
        }

        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 1, prices, fee, dp);
    }
};
