class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        vector<vector<double>> dp(m+1, vector<double>(n+1,0));
        for(int p=0; p<=m; p++){
            dp[p][0] = 1;
        }
        for(int q=1; q<=n; q++){
            dp[0][q] = 0;
        }
        for(int i = 1; i<=m ; i++){
            for(int j = 1; j<=n; j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return (double)dp[m][n];
    }
};