class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<tuple<int, int, int>> jobs;

        for (int i = 0; i < n; ++i) {
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());

        vector<int> dp(n, 0);
        vector<int> endTimes(n);

        for (int i = 0; i < n; ++i) {
            endTimes[i] = get<0>(jobs[i]);
        }

        for (int i = 0; i < n; ++i) {
            int s = get<1>(jobs[i]);
            int p = get<2>(jobs[i]);

            int l = 0, r = i - 1, lastNonOverlap = -1;
            while (l <= r) {
                int m = (l + r) / 2;
                if (endTimes[m] <= s) {
                    lastNonOverlap = m;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }

            int includeProfit = p + (lastNonOverlap == -1 ? 0 : dp[lastNonOverlap]);
            int excludeProfit = (i == 0 ? 0 : dp[i - 1]);

            dp[i] = max(includeProfit, excludeProfit);
        }

        return dp[n - 1];
    }
};
