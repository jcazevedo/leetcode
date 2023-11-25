// 1312. Minimum Insertion Steps to Make a String Palindrome
// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int minInsertions(string s) {
    int N = s.size();
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; ++i)
      for (int j = 1; j <= N; ++j)
        if (s[i - 1] == s[N - j])
          dp[i][j] = dp[i - 1][j - 1] + 1;
        else
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    return N - dp[N][N];
  }
};
