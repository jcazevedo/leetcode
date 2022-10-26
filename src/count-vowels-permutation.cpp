#include <vector>

using namespace std;

#define MOD 1000000007

class Solution {
 public:
  int countVowelPermutation(int n) {
    vector<vector<long long>> dp(n + 1, vector<long long>(5, 0));
    for (int i = 0; i < 5; ++i) dp[1][i] = 1;
    for (int i = 1; i <= n; ++i) {
      // Each vowel 'a' may only be followed by an 'e'.
      dp[i][1] = (dp[i][1] + dp[i - 1][0]) % MOD;
      // Each vowel 'e' may only be followed by an 'a' or an 'i'.
      dp[i][0] = (dp[i][0] + dp[i - 1][1]) % MOD;
      dp[i][2] = (dp[i][2] + dp[i - 1][1]) % MOD;
      // Each vowel 'i' may not be followed by another 'i'.
      for (int curr_ch = 0; curr_ch < 5; ++curr_ch) {
        if (curr_ch == 2) continue;
        dp[i][curr_ch] = (dp[i][curr_ch] + dp[i - 1][2]) % MOD;
      }
      // Each vowel 'o' may only be followed by an 'i' or a 'u'.
      dp[i][2] = (dp[i][2] + dp[i - 1][3]) % MOD;
      dp[i][4] = (dp[i][4] + dp[i - 1][3]) % MOD;
      // Each vowel 'u' may only be followed by an 'a'.
      dp[i][0] = (dp[i][0] + dp[i - 1][4]) % MOD;
    }
    long long ans = 0;
    for (int ch = 0; ch < 5; ++ch) {
      ans = (ans + dp[n][ch]) % MOD;
    }
    return ans;
  }
};
