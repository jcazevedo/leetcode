// 1035. Uncrossed Lines
// https://leetcode.com/problems/uncrossed-lines/

#include <vector>

using namespace std;

class Solution {
 public:
  int maxUncrossedLines(vector<int>& A, vector<int>& B) {
    int NA = A.size();
    int NB = B.size();
    vector<vector<int>> dp(NA + 1, vector<int>(NB + 1));
    for (int a = 1; a <= NA; ++a) {
      for (int b = 1; b <= NB; ++b) {
        dp[a][b] = max(dp[a - 1][b], dp[a][b - 1]);
        if (A[a - 1] == B[b - 1])
          dp[a][b] = max(dp[a][b], dp[a - 1][b - 1] + 1);
      }
    }
    return dp[NA][NB];
  }
};
