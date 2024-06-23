// 664. Strange Printer
// https://leetcode.com/problems/strange-printer/

#include <string>
#include <vector>

using namespace std;

class Solution {
 private:
  int go(int l, int r, const string& s, vector<vector<int>>& dp) {
    if (dp[l][r] != -1) return dp[l][r];
    dp[l][r] = s.size();
    int j = -1;
    for (int i = l; i < r; ++i) {
      if (s[i] != s[r] && j == -1) j = i;
      if (j != -1) dp[l][r] = min(dp[l][r], 1 + go(j, i, s, dp) + go(i + 1, r, s, dp));
    }
    if (j == -1) dp[l][r] = 0;
    return dp[l][r];
  }

 public:
  int strangePrinter(string s) {
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
    return go(0, s.size() - 1, s, dp) + 1;
  }
};
