// 1895. Largest Magic Square
// https://leetcode.com/problems/largest-magic-square/

#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
 public:
  int largestMagicSquare(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> rowSum(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
      rowSum[i][0] = grid[i][0];
      for (int j = 1; j < n; ++j) { rowSum[i][j] = rowSum[i][j - 1] + grid[i][j]; }
    }
    vector<vector<int>> colSum(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
      colSum[i][0] = grid[0][i];
      for (int j = 1; j < m; ++j) { colSum[i][j] = colSum[i][j - 1] + grid[j][i]; }
    }
    int ans = 1;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int l = ans; l <= min(m - i, n - j); ++l) {
          int target = rowSum[i][j + l - 1];
          if (j > 0) { target -= rowSum[i][j - 1]; }
          bool isMagic = true;
          for (int r = 1; r < l && isMagic; ++r) {
            int rs = rowSum[i + r][j + l - 1];
            if (j > 0) { rs -= rowSum[i + r][j - 1]; }
            if (rs != target) {
              isMagic = false;
              break;
            }
          }
          for (int c = 0; c < l && isMagic; ++c) {
            int cs = colSum[j + c][i + l - 1];
            if (i > 0) { cs -= colSum[j + c][i - 1]; }
            if (cs != target) {
              isMagic = false;
              break;
            }
          }
          if (!isMagic) { continue; }
          int di = i;
          int dj = j;
          int dl = l;
          int dSum = 0;
          while (dl--) {
            dSum += grid[di][dj];
            ++di;
            ++dj;
          }
          if (dSum != target) { continue; }
          di = i;
          dj = j + l - 1;
          dl = l;
          dSum = 0;
          while (dl--) {
            dSum += grid[di][dj];
            ++di;
            --dj;
          }
          if (dSum != target) { continue; }
          ans = max(ans, l);
        }
      }
    }
    return ans;
  }
};
