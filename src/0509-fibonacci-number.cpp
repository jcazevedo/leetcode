// 509. Fibonacci Number
// https://leetcode.com/problems/fibonacci-number/

#include <cstring>

class Solution {
private:
  int dp[31];

  int go(int n) {
    if (n == 0)
      return 0;
    if (n == 1)
      return 1;
    if (dp[n] == -1)
      return go(n - 1) + go(n - 2);
    return dp[n];
  }

public:
  int fib(int n) {
    memset(dp, -1, sizeof(dp));
    return go(n);
  }
};
