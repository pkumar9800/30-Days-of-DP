class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length();
        int len2 = text2.length();

        vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));

        for(int ind1=1; ind1<=len1; ind1++){
            for(int ind2=1; ind2<=len2; ind2++){
                if(text1[ind1-1]==text2[ind2-1]){
                    dp[ind1][ind2] = 1+dp[ind1-1][ind2-1];
                }
                else{
                    dp[ind1][ind2] = max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
                }
            }
        }
        return dp[len1][len2];
    }
};