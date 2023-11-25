// 1269. Number of Ways to Stay in the Same Place After Some Steps
// https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/

#include <algorithm>
#include <vector>

using namespace std;

#define MOD 1000000007

class Solution {
 public:
  int numWays(int steps, int arrLen) {
    arrLen = min(arrLen, steps);
    vector<vector<int>> dp(arrLen, vector<int>(2));
    int curr = 0, prev = 1;
    dp[0][curr] = 1;
    for (int i = 1; i < arrLen; ++i) dp[i][curr] = 0;
    for (int step = 1; step <= steps; ++step) {
      swap(prev, curr);
      for (int i = arrLen - 1; i >= 0; --i) {
        int v = dp[i][prev];
        if (i > 0) v = (v + dp[i - 1][prev]) % MOD;
        if (i + 1 < arrLen) v = (v + dp[i + 1][prev]) % MOD;
        dp[i][curr] = v;
      }
    }
    return dp[0][curr];
  }
};
