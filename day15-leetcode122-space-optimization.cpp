class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<long> ahead(2, 0), curr(2, 0);

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy == 0) {
                    curr[buy] = max(0 + ahead[0], -prices[ind] + ahead[1]);
                } else {
                    curr[buy] = max(0 + ahead[1], prices[ind] + ahead[0]);
                }
            }
            ahead = curr;
        }

        return ahead[0];
    }
};
