// 3212. Count Submatrices With Equal Frequency of X and Y
// https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/

#include <vector>

using namespace std;

class Solution {
 public:
  int numberOfSubmatrices(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size(), ans = 0;
    vector<vector<int>> sum = vector<vector<int>>(m, vector<int>(n, 0));
    vector<vector<bool>> good = vector<vector<bool>>(m, vector<bool>(n, false));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 'X') {
          good[i][j] = true;
          sum[i][j] += 1;
        } else if (grid[i][j] == 'Y') {
          sum[i][j] -= 1;
        }
        if (i > 0) {
          good[i][j] = good[i][j] || good[i - 1][j];
          sum[i][j] += sum[i - 1][j];
        }
        if (j > 0) {
          good[i][j] = good[i][j] || good[i][j - 1];
          sum[i][j] += sum[i][j - 1];
        }
        if (i > 0 && j > 0) { sum[i][j] -= sum[i - 1][j - 1]; }
        if (sum[i][j] == 0 && good[i][j]) { ++ans; }
      }
    }
    return ans;
  }
};
