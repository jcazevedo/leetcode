// 3418. Maximum Amount of Money Robot Can Earn
// https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/

#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

class Solution {
 private:
  static vector<vector<int>> dirs;

 public:
  int maximumAmount(vector<vector<int>>& coins) {
    int m = coins.size(), n = coins[0].size();
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, numeric_limits<int>::min())));
    dp[0][0][0] = coins[0][0];
    if (coins[0][0] < 0) { dp[0][0][1] = 0; }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < 3; k++) {
          if (dp[i][j][k] == numeric_limits<int>::min()) { continue; }
          int val = dp[i][j][k];
          for (int d = 0; d < 2; ++d) {
            int di = dirs[d][0];
            int dj = dirs[d][1];
            int ni = i + di, nj = j + dj;
            if (ni >= m || nj >= n) { continue; }
            dp[ni][nj][k] = max(dp[ni][nj][k], val + coins[ni][nj]);
            if (coins[ni][nj] < 0 && k + 1 < 3) { dp[ni][nj][k + 1] = max(dp[ni][nj][k + 1], val); }
          }
        }
      }
    }
    return max({dp[m - 1][n - 1][0], dp[m - 1][n - 1][1], dp[m - 1][n - 1][2]});
  }
};

vector<vector<int>> Solution::dirs = {{0, 1}, {1, 0}};
