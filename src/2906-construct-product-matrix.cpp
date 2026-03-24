// 2906. Construct Product Matrix
// https://leetcode.com/problems/construct-product-matrix/

#include <vector>

using namespace std;

#define MOD 12345

class Solution {
 public:
  vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<long long> pre(n * m, 1L), suf(n * m, 1L);
    pre[0] = grid[0][0] % MOD;
    for (int i = 0; i < n; ++i) {
      for (int j = i == 0 ? 1 : 0; j < m; ++j) {
        int ii = i * m + j;
        pre[ii] = (pre[ii - 1] * grid[i][j]) % MOD;
      }
    }
    suf[n * m - 1] = grid[n - 1][m - 1] % MOD;
    for (int i = n - 1; i >= 0; --i) {
      for (int j = i == n - 1 ? m - 2 : m - 1; j >= 0; --j) {
        int ii = i * m + j;
        suf[ii] = (suf[ii + 1] * grid[i][j]) % MOD;
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int ii = i * m + j;
        if (ii == 0) {
          grid[i][j] = suf[ii + 1];
        } else if (ii == n * m - 1) {
          grid[i][j] = pre[ii - 1];
        } else {
          grid[i][j] = (pre[ii - 1] * suf[ii + 1]) % MOD;
        }
      }
    }
    return grid;
  }
};
