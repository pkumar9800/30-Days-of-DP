class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned long long>> dp(n, vector<unsigned long long>(amount + 1, 0));

        // Base case: 1 way to make amount 0 (use no coins)
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        // Initialize for the first coin
        for (int target = 1; target <= amount; target++) {
            if (target % coins[0] == 0) {
                dp[0][target] = 1;
            }
        }

        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= amount; target++) {
                unsigned long long notPick = dp[ind - 1][target];
                unsigned long long pick = 0;
                if (coins[ind] <= target) {
                    pick = dp[ind][target - coins[ind]];
                }
                dp[ind][target] = notPick + pick;
            }
        }
        return (int)dp[n - 1][amount];
    }
};