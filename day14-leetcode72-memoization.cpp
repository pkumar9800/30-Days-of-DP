class Solution {
private:
    int fun(int i, int j, string& word1, string& word2, vector<vector<int>>& dp){
        if(i==0) return j;
        if(j==0) return i;

        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i-1]==word2[j-1]){
            return dp[i][j] = fun(i-1, j-1, word1, word2, dp);
        }
        else{
            int insert = 1 + fun(i, j-1, word1, word2, dp);
            int del = 1 + fun(i-1, j, word1, word2, dp);
            int rep = 1 + fun(i-1, j-1, word1, word2, dp);
            return dp[i][j] = min(insert, min(del, rep));
        }
    }
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        return fun(m, n, word1, word2, dp);
    }
};