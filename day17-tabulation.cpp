class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));
        for(int ind =n-1; ind>=0; ind--){
            for(int tranNo = 2*k-1; tranNo>=0; tranNo--){
                int profit = 0;
                if(tranNo % 2 == 0){
                    int b = -prices[ind] + dp[ind+1][tranNo + 1];
                    int nb =  0 + dp[ind+1][tranNo];
                    profit = max(b,nb);
                }
                else{
                    int s = prices[ind] + dp[ind+1][tranNo + 1];
                    int ns = dp[ind+1][tranNo];
                    profit = max(s,ns);
                }
                dp[ind][tranNo] = profit; 
            }
        }
        return dp[0][0];
    }
};