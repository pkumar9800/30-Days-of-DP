class Solution {
private:
    int minSumPathUtil(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
        if (i == 0 && j == 0)
            return matrix[0][0];

        if (dp[i][j] != -1)
            return dp[i][j];

        int up = INT_MAX, left = INT_MAX;
        if (i > 0)
            up = matrix[i][j] + minSumPathUtil(i - 1, j, matrix, dp);
        if (j > 0)
            left = matrix[i][j] + minSumPathUtil(i, j - 1, matrix, dp);

        return dp[i][j] = min(up, left);
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return minSumPathUtil(n - 1, m - 1, grid, dp);
    }
};
