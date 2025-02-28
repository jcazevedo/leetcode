// 1092. Shortest Common Supersequence
// https://leetcode.com/problems/shortest-common-supersequence/

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string shortestCommonSupersequence(string str1, string str2) {
    int N1 = str1.size(), N2 = str2.size();
    vector<vector<int>> dp(N1 + 1, vector<int>(N2 + 1, 0));
    for (int i1 = 1; i1 <= N1; ++i1) {
      for (int i2 = 1; i2 <= N2; ++i2) {
        if (str1[i1 - 1] == str2[i2 - 1]) {
          dp[i1][i2] = dp[i1 - 1][i2 - 1] + 1;
        } else {
          dp[i1][i2] = max(dp[i1 - 1][i2], dp[i1][i2 - 1]);
        }
      }
    }
    string ans = "";
    while (N1 > 0 && N2 > 0) {
      if (str1[N1 - 1] == str2[N2 - 1]) {
        ans += str1[N1 - 1];
        N1--;
        N2--;
      } else if (dp[N1 - 1][N2] > dp[N1][N2 - 1]) {
        ans += str1[N1 - 1];
        N1--;
      } else {
        ans += str2[N2 - 1];
        N2--;
      }
    }
    while (N1 > 0) { ans += str1[--N1]; }
    while (N2 > 0) { ans += str2[--N2]; }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
