// 64. Minimum Path Sum
// https://leetcode.com/problems/minimum-path-sum/

#include <limits>
#include <vector>

using namespace std;

typedef long long ll;

class Solution {
 private:
  ll minPath(int i, int j, vector<vector<int>>& grid, vector<vector<ll>>& dp) {
    if (dp[i][j] == numeric_limits<ll>::max()) {
      if (i - 1 >= 0) dp[i][j] = min(dp[i][j], grid[i][j] + minPath(i - 1, j, grid, dp));
      if (j - 1 >= 0) dp[i][j] = min(dp[i][j], grid[i][j] + minPath(i, j - 1, grid, dp));
    }
    return dp[i][j];
  }

 public:
  int minPathSum(vector<vector<int>>& grid) {
    int H = grid.size(), W = grid[0].size();
    vector<vector<ll>> dp = vector<vector<ll>>(H, vector<ll>(W, numeric_limits<ll>::max()));
    dp[0][0] = grid[0][0];
    return minPath(H - 1, W - 1, grid, dp);
  }
};
