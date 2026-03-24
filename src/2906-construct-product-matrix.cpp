// 2906. Construct Product Matrix
// https://leetcode.com/problems/construct-product-matrix/

#include <vector>

using namespace std;

#define MOD 12345

class Solution {
 public:
  vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> res(n, vector<int>(m, 1));
    int suf = 1;
    for (int i = n - 1; i >= 0; --i) {
      for (int j = m - 1; j >= 0; --j) {
        res[i][j] = suf;
        suf = (suf * (grid[i][j] % MOD)) % MOD;
      }
    }
    int pre = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        res[i][j] = (res[i][j] * pre) % MOD;
        pre = (pre * (grid[i][j] % MOD)) % MOD;
      }
    }
    return res;
  }
};
