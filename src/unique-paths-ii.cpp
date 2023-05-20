#include <vector>

using namespace std;

class Solution {
private:
  vector<vector<int>> dp;

  int go(int i, int j, vector<vector<int>>& grid) {
    if (dp[i][j] != -1)
      return dp[i][j];
    if (grid[i][j] == 1)
      return dp[i][j] = 0;
    if (i == 0 && j == 0)
      return dp[i][j] = 1;
    dp[i][j] = 0;
    if (i - 1 >= 0)
      dp[i][j] += go(i - 1, j, grid);
    if (j - 1 >= 0)
      dp[i][j] += go(i, j - 1, grid);
    return dp[i][j];
  }

public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int H = obstacleGrid.size();
    int W = obstacleGrid[0].size();
    dp.assign(H, vector<int>(W, -1));
    return go(H - 1, W - 1, obstacleGrid);
  }
};
