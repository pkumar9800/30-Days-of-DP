class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<int> prev(n+1, 0), cur(n+1, 0);
        for(int j = 0; j<=n; j++){
            prev[j] = j;
        }
        for(int i=1; i<=m; i++){
            cur[0] = i;
            for(int j=1; j<=n; j++){
                if(word1[i-1]==word2[j-1]){
                    cur[j] = prev[j-1];
                }
                else{
                    int insert = 1 + cur[j-1];
                    int del = 1 + prev[j];
                    int rep = 1 +prev[j-1];
                    cur[j] = min(insert, min(del, rep));
                }
            }
            prev=cur;
        }
        return prev[n];
    }
};