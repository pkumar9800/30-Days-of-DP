class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<unsigned long> prev(amount + 1, 0);

        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0)
                prev[i] = 1;  
        }

        for (int ind = 1; ind < n; ind++) {
            vector<unsigned long> cur(amount + 1, 0);
            for (int target = 0; target <= amount; target++) {
                unsigned long notTaken = prev[target];

                unsigned long taken = 0;
                if (coins[ind] <= target)
                    taken = cur[target - coins[ind]];

                cur[target] = notTaken + taken;
            }
            prev = cur;
        }
        return (int)prev[amount]; 
    }
};