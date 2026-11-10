// 3693. Climbing Stairs II
// https://leetcode.com/problems/climbing-stairs-ii/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int climbStairs(int n, vector<int>& costs) {
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    for (int i = 0; i <= n; ++i) {
      for (int j = 1; j <= 3 && i + j <= n; ++j) {
        if (dp[i + j] == -1) {
          dp[i + j] = dp[i] + costs[i + j - 1] + j * j;
        } else {
          dp[i + j] = min(dp[i + j], dp[i] + costs[i + j - 1] + j * j);
        }
      }
    }
    return dp[n];
  }
};
