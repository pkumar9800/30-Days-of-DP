//Memoization Approach
class Solution {
  private:
  int mazeObstaclesUtil(int i, int j, vector<vector<int>> &maze, vector<vector<int>> &dp) {
      if (i < 0 || j < 0) return 0;
      if (maze[i][j] == 1) return 0;
      if (i == 0 && j == 0) return 1;
      if (dp[i][j] != -1) return dp[i][j];
  
      int up = mazeObstaclesUtil(i - 1, j, maze, dp);
      int left = mazeObstaclesUtil(i, j - 1, maze, dp);
  
      return dp[i][j] = up + left;
  }
  
  public:
      int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
          int n = obstacleGrid.size();
          int m = obstacleGrid[0].size();
          vector<vector<int>> dp(n, vector<int>(m, -1));
          return mazeObstaclesUtil(n - 1, m - 1, obstacleGrid, dp);
      }
  };
