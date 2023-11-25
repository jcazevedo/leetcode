// 730. Count Different Palindromic Subsequences
// https://leetcode.com/problems/count-different-palindromic-subsequences/

#include <string>
#include <vector>

using namespace std;

#define MOD 1000000007

class Solution {
 private:
  int mod_add(int a, int b) { return ((long long)a + b) % MOD; }

  int mod_sub(int a, int b) { return ((long long)a + MOD - b) % MOD; }

  int go(
      int i, int j, int ch, const string& s, vector<vector<vector<int>>>& dp) {
    if (i > j) return 0;
    if (i == j) {
      if (s[j] == (ch + 'a')) return 1;
      return 0;
    }
    if (dp[i][j][ch] != -1) return dp[i][j][ch];
    dp[i][j][ch] = 0;
    if (s[i] == s[j] && s[j] == (ch + 'a')) {
      dp[i][j][ch] = 2;
      for (int nch = 0; nch < 4; ++nch)
        dp[i][j][ch] = mod_add(dp[i][j][ch], go(i + 1, j - 1, nch, s, dp));
    } else {
      dp[i][j][ch] = mod_add(dp[i][j][ch], go(i + 1, j, ch, s, dp));
      dp[i][j][ch] = mod_add(dp[i][j][ch], go(i, j - 1, ch, s, dp));
      dp[i][j][ch] = mod_sub(dp[i][j][ch], go(i + 1, j - 1, ch, s, dp));
    }
    return dp[i][j][ch];
  }

 public:
  int countPalindromicSubsequences(string s) {
    int N = s.size();
    vector<vector<vector<int>>> dp(N,
                                   vector<vector<int>>(N, vector<int>(4, -1)));
    int ans = 0;
    for (int i = 0; i < 4; ++i) ans = mod_add(ans, go(0, N - 1, i, s, dp));
    return ans;
  }
};
