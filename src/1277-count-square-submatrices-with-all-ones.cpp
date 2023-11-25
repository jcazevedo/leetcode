// 1277. Count Square Submatrices with All Ones
// https://leetcode.com/problems/count-square-submatrices-with-all-ones/

#include <vector>

using namespace std;

class Solution {
 public:
  int countSquares(vector<vector<int>>& matrix) {
    int H = matrix.size(), W = matrix[0].size();
    vector<vector<int>> dp(H, vector<int>(W, 0));
    int tot = 0;
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        if (matrix[i][j] == 1) {
          int prev;
          if (i > 0 && j > 0)
            prev = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
          else
            prev = 0;
          dp[i][j] = prev + 1;
          tot += dp[i][j];
        }
      }
    }
    return tot;
  }
};
