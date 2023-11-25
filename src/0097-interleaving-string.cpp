// 97. Interleaving String
// https://leetcode.com/problems/interleaving-string/

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    int N1 = s1.size(), N2 = s2.size(), N3 = s3.size();
    if (N3 != N1 + N2) { return false; }
    vector<vector<bool>> dp(N1 + 1, vector<bool>(N2 + 1, false));
    dp[0][0] = true;
    for (int i3 = 1; i3 <= N3; ++i3) {
      int prev = i3 - 1;
      for (int i1 = 0; i1 <= min(N1, prev); ++i1) {
        int i2 = prev - i1;
        if (i2 > N2) continue;
        if (dp[i1][i2]) {
          if (i1 + 1 <= N1) dp[i1 + 1][i2] = s3[i3 - 1] == s1[i1];
          if (i2 + 1 <= N2) dp[i1][i2 + 1] = s3[i3 - 1] == s2[i2];
        }
      }
    }
    return dp[N1][N2];
  }
};
