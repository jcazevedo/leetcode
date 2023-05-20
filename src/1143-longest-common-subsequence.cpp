// 1143. Longest Common Subsequence
// https://leetcode.com/problems/longest-common-subsequence/

#include <string>

using namespace std;

class Solution {
private:
  static const int MAXA = 1000, MAXB = 1000;
  int dp[MAXA + 1][MAXB + 1];

public:
  int longestCommonSubsequence(string text1, string text2) {
    int NA = text1.size();
    int NB = text2.size();
    for (int a = 0; a <= NA; ++a)
      dp[a][0] = 0;
    for (int b = 0; b <= NB; ++b)
      dp[0][b] = 0;
    for (int a = 1; a <= NA; ++a) {
      for (int b = 1; b <= NB; ++b) {
        if (text1[a - 1] == text2[b - 1])
          dp[a][b] = dp[a - 1][b - 1] + 1;
        else
          dp[a][b] = max(dp[a - 1][b], dp[a][b - 1]);
      }
    }
    return dp[NA][NB];
  }
};
