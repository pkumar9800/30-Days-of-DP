class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int ind = n-1; ind>=0; ind--){
            for(int prev_ind = ind-1; prev_ind>=-1; prev_ind--){
                int notPick = 0 + dp[ind+1][prev_ind+1];
                int pick = 0;
                if(prev_ind==-1|| nums[ind]>nums[prev_ind]){
                    pick = 1 + dp[ind+1][ind+1];
                }
                dp[ind][prev_ind+1] = max(pick, notPick);
            }
        }
        return dp[0][0];
    }
};