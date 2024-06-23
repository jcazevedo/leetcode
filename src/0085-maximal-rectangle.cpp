// 85. Maximal Rectangle
// https://leetcode.com/problems/maximal-rectangle/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> dp(rows, vector<int>(cols, 0));
    for (int c = 0; c < cols; ++c) {
      if (matrix[0][c] == '1') { dp[0][c] = 1; }
    }
    for (int r = 1; r < rows; ++r) {
      for (int c = 0; c < cols; ++c) {
        if (matrix[r][c] == '1') { dp[r][c] = dp[r - 1][c] + 1; }
      }
    }
    int ans = 0;
    for (int r = 0; r < rows; ++r) {
      for (int c = 0; c < cols; ++c) {
        int height = dp[r][c];
        for (int k = c; k >= 0 && dp[r][k] > 0; --k) {
          height = min(height, dp[r][k]);
          ans = max(ans, height * (c - k + 1));
        }
      }
    }
    return ans;
  }
};
