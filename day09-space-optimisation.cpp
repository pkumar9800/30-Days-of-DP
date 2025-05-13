class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length();
        int len2 = text2.length();

        vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
        vector<int> prev(len2+1, 0), curr(len2+1, 0);

        for(int ind1=1; ind1<=len1; ind1++){
            for(int ind2=1; ind2<=len2; ind2++){
                if(text1[ind1-1]==text2[ind2-1]){
                    curr[ind2] = 1+prev[ind2-1];
                }
                else{
                    curr[ind2] = max(prev[ind2], curr[ind2-1]);
                }
            }
            prev = curr;
        }
        return prev[len2];
    }
};