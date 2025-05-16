class Solution {
private:
void longestCommonSubsequence(string text1, string text2,  vector<vector<int>>& dp) {
        int len1 = text1.length();
        int len2 = text2.length();
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
    }        
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        longestCommonSubsequence(str1, str2, dp);
        int i = m, j = n;
        string ans = "";
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                ans = ans + str1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                ans = ans + str1[i-1];
                i--;
            }
            else{
                ans = ans + str2[j-1];
                j--;
            }
        }
        while(i>0){
            ans = ans + str1[i-1];
            i--;
        }
        while(j>0){
            ans = ans + str2[j-1];
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};