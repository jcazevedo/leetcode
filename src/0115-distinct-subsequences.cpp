// 115. Distinct Subsequences
// https://leetcode.com/problems/distinct-subsequences/

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int numDistinct(string s, string t) {
    int S = s.size();
    int T = t.size();
    vector<vector<double>> dp(S + 1, vector<double>(T + 1, 0.0));
    for (int i = 0; i <= S; ++i) { dp[i][0] = 1; }
    for (int i = 1; i <= S; ++i) {
      for (int j = 1; j <= T; ++j) {
        dp[i][j] += dp[i - 1][j];
        if (s[i - 1] == t[j - 1]) { dp[i][j] += dp[i - 1][j - 1]; }
      }
    }
    return (int)dp[S][T];
  }
};
