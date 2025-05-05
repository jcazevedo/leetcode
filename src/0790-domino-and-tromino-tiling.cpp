// 790. Domino and Tromino Tiling
// https://leetcode.com/problems/domino-and-tromino-tiling/

#include <vector>

using namespace std;

#define MOD 1000000007

class Solution {
 private:
  int mod_add(long long a, long long b) { return (a + b) % MOD; }

 public:
  int numTilings(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1L;
    for (int i = 1; i <= n; ++i) {
      dp[i] = mod_add(dp[i], dp[i - 1]);
      if (i - 2 >= 0) { dp[i] = mod_add(dp[i], dp[i - 2]); }
      for (int j = i - 3; j >= 0; --j) {
        dp[i] = mod_add(dp[i], dp[j]);
        dp[i] = mod_add(dp[i], dp[j]);
      }
    }
    return dp[n];
  }
};
