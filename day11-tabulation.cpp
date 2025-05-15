class Solution {
private:
    int longestCommonSubsequence(string s, string t){
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
public:
    int minInsertions(string s) {
        int n = s.length();
        string t = s;
        reverse(s.begin(), s.end());
        int l = longestCommonSubsequence(s,t);
        return n-l;
    }
};