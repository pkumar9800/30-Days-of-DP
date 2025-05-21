class Solution {
private:
    int fun(int ind, int tranNo, int n, int k, vector<int>& prices, vector<vector<int>>& dp){
        if(ind == n || tranNo == 2*k) return 0;
        if(dp[ind][tranNo]!=-1) return dp[ind][tranNo];
        int profit = 0;
        if(tranNo % 2 == 0){
            int b = -prices[ind] + fun(ind+1, tranNo + 1, n, k, prices, dp);
            int nb =  0 + fun(ind+1, tranNo, n, k, prices, dp);
            profit = max(b,nb);
        }
        else{
            int s = prices[ind] + fun(ind+1, tranNo + 1, n, k, prices, dp);
            int ns = fun(ind+1, tranNo, n, k, prices, dp);
            profit = max(s,ns);
        }
        return dp[ind][tranNo] = profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2*k, -1));
        return fun(0, 0, n, k, prices, dp);
    }
};