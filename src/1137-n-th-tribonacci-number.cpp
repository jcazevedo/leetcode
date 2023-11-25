// 1137. N-th Tribonacci Number
// https://leetcode.com/problems/n-th-tribonacci-number/

#include <cstring>

class Solution {
 private:
  int dp[38];

  int go(int n) {
    if (n == 0) return 0;
    if (n <= 2) return 1;
    if (dp[n] == -1) dp[n] = go(n - 1) + go(n - 2) + go(n - 3);
    return dp[n];
  }

 public:
  int tribonacci(int n) {
    memset(dp, -1, sizeof(dp));
    return go(n);
  }
};
