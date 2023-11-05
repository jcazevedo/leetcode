// 712. Minimum ASCII Delete Sum for Two Strings
// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int minimumDeleteSum(string s1, string s2) {
    int N1 = s1.size(), N2 = s2.size();
    vector<vector<int>> dp(N1 + 1, vector<int>(N2 + 1, 0));
    vector<vector<int>> sum(N1 + 1, vector<int>(N2 + 1, 0));
    for (int i1 = 1; i1 <= N1; ++i1)
      for (int i2 = 1; i2 <= N2; ++i2)
        if (s1[i1 - 1] == s2[i2 - 1]) {
          dp[i1][i2] = dp[i1 - 1][i2 - 1] + 1;
          sum[i1][i2] = sum[i1 - 1][i2 - 1] + s1[i1 - 1];
        } else if (dp[i1 - 1][i2] > dp[i1][i2 - 1] ||
                   (dp[i1 - 1][i2] == dp[i1][i2 - 1] && sum[i1 - 1][i2] > sum[i1][i2 - 1])) {
          dp[i1][i2] = dp[i1 - 1][i2];
          sum[i1][i2] = sum[i1 - 1][i2];
        } else {
          dp[i1][i2] = dp[i1][i2 - 1];
          sum[i1][i2] = sum[i1][i2 - 1];
        }
    int sum1 = 0, sum2 = 0;
    for (char ch : s1)
      sum1 += ch;
    for (char ch : s2)
      sum2 += ch;
    return (sum1 - sum[N1][N2]) + (sum2 - sum[N1][N2]);
  }
};
