class Solution {
private:
    int fun(int ind1, int ind2, string &text1, string &text2, vector<vector<int>>& dp){
        if(ind1 < 0 || ind2 < 0){
            return 0;
        }

        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(text1[ind1]==text2[ind2]){
            return dp[ind1][ind2] = 1+fun(ind1-1, ind2-1, text1, text2, dp);
        }
        else{
            return dp[ind1][ind2] = max(fun(ind1-1, ind2, text1, text2, dp), fun(ind1, ind2-1, text1, text2, dp));
        }
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length();
        int len2 = text2.length();

        vector<vector<int>> dp(len1, vector<int>(len2, -1));
        return fun(len1-1, len2-1, text1, text2, dp);
    }
};