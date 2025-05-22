class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for(int ind=n-1; ind>=0; ind--){
            for(int buy = 0; buy<=1; buy++){
                int profit = 0;
                if(buy){
                    int b = -prices[ind] + dp[ind+1][0];
                    int nb = dp[ind+1][1];
                    profit = max(b,nb);
                }
                else{
                    int s = prices[ind] - fee + dp[ind+1][1];
                    int ns = dp[ind+1][0];
                    profit = max(s,ns);
                }
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }
};