class Solution {
private:
    int fun(int ind, int prev_ind, vector<int>& nums,  int n, vector<vector<int>>& dp){
        if(ind == n) return 0;

        if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];

        int notPick = 0 + fun(ind+1, prev_ind, nums, n, dp);
        int pick = 0;
        if(prev_ind==-1|| nums[ind]>nums[prev_ind]){
            pick = 1 + fun(ind+1, ind, nums, n, dp);
        }
        return dp[ind][prev_ind+1] = max(pick, notPick);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return fun(0, -1, nums, n, dp);
    }
};