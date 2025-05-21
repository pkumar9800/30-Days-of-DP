class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> after(2*k+1, 0);
        vector<int> cur(2*k+1, 0);
        for(int ind =n-1; ind>=0; ind--){
            for(int tranNo = 2*k-1; tranNo>=0; tranNo--){
                int profit = 0;
                if(tranNo % 2 == 0){
                    int b = -prices[ind] + after[tranNo + 1];
                    int nb =  0 + after[tranNo];
                    profit = max(b,nb);
                }
                else{
                    int s = prices[ind] + after[tranNo + 1];
                    int ns = after[tranNo];
                    profit = max(s,ns);
                }
                cur[tranNo] = profit; 
            }
            after = cur;
        }
        return after[0];
    }
};