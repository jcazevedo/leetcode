// 3070. Count Submatrices with Top-Left Element and Sum Less Than k
// https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/

#include <vector>

using namespace std;

class Solution {
 public:
  int countSubmatrices(vector<vector<int>>& grid, int k) {
    int m = grid.size(), n = grid[0].size(), ans = 0;
    vector<vector<int>> sum = vector<vector<int>>(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        sum[i][j] += grid[i][j];
        if (i > 0) { sum[i][j] += sum[i - 1][j]; }
        if (j > 0) { sum[i][j] += sum[i][j - 1]; }
        if (i > 0 && j > 0) { sum[i][j] -= sum[i - 1][j - 1]; }
        if (sum[i][j] <= k) { ++ans; }
      }
    }
    return ans;
  }
};
