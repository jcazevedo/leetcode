// 2742. Painting the Walls
// https://leetcode.com/problems/painting-the-walls/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int paintWalls(vector<int>& cost, vector<int>& time) {
    int n = cost.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1e9));
    for (int i = 0; i <= n; ++i) { dp[i][0] = 0; }
    for (int i = n - 1; i >= 0; --i) {
      for (int r = 1; r <= n; ++r) { dp[i][r] = min(dp[i + 1][r], cost[i] + dp[i + 1][max(0, r - time[i] - 1)]); }
    }
    return dp[0][n];
  }
};
