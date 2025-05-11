class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totSum = 0;
        for (int i = 0; i < n; i++) {
            totSum += nums[i];
        }
        if (totSum % 2 == 1)
            return false;
        else {
            int k = totSum / 2;
            vector<bool> prev(k + 1, false);
            prev[0] = true;
            if (nums[0] <= k)
                prev[nums[0]] = true;

            for (int ind = 1; ind < n; ind++) {
                vector<bool> cur(k + 1, false);
                cur[0] = true;
                for (int target = 1; target <= k; target++) {
                    bool notTaken = prev[target];
                    bool taken = false;
                    if (nums[ind] <= target)
                        taken = prev[target - nums[ind]];
                    cur[target] = notTaken || taken;
                }
                prev = cur;
            }
            return prev[k];
        }
    }
};