class Solution {
bool fun(int ind, int target, vector<int>& nums, vector<vector<int>>& dp){
    if(target == 0){
        return true;
    }
    if(ind == 0){
        return nums[0] == target;
    }
    if(dp[ind][target] != -1) return dp[ind][target];
    bool nonTake = fun(ind-1, target, nums, dp);
    bool take = false;
    if(nums[ind]<=target){
        take = fun(ind-1, target-nums[ind], nums, dp);
    }
    return dp[ind][target] = take | nonTake;
}
public:
    bool canPartition(vector<int>& nums) {
        //obtain array sum
        int lengthOfNums = nums.size();
        int arraySum=0;
        for(int i=0; i<lengthOfNums; i++){
            arraySum+=nums[i];
        }
        if(arraySum & 1){
            return false;
        }
        int s1 = arraySum/2;
        vector<vector<int>> dp(lengthOfNums, vector<int>(s1+1, -1));
        return fun(lengthOfNums-1, s1, nums, dp);
    }
};