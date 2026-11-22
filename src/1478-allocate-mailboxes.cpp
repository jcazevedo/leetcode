// 1478. Allocate Mailboxes
// https://leetcode.com/problems/allocate-mailboxes/

#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

class Solution {
 public:
  int minDistance(vector<int>& houses, int k) {
    sort(houses.begin(), houses.end());
    int n = houses.size();
    vector<vector<int>> cost(n, vector<int>(n, 0));
    for (int l = n - 1; l >= 0; --l) {
      for (int r = l + 1; r < n; ++r) { cost[l][r] = houses[r] - houses[l] + (l + 1 < r ? cost[l + 1][r - 1] : 0); }
    }
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, numeric_limits<int>::max() / 2));
    dp[0][0] = 0;
    for (int m = 1; m <= k; ++m) {
      for (int i = m; i <= n; ++i) {
        for (int t = m - 1; t < i; ++t) { dp[m][i] = min(dp[m][i], dp[m - 1][t] + cost[t][i - 1]); }
      }
    }
    return dp[k][n];
  }
};
