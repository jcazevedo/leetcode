// 840. Magic Squares In Grid
// https://leetcode.com/problems/magic-squares-in-grid/

#include <vector>

using namespace std;

class Solution {
 public:
  int numMagicSquaresInside(vector<vector<int>>& grid) {
    int R = grid.size();
    int C = grid[0].size();
    int ans = 0;
    for (int r = 0; r + 3 <= R; ++r) {
      for (int c = 0; c + 3 <= C; ++c) {
        vector<int> cnt(20, 0);
        vector<int> row(3, 0);
        vector<int> col(3, 0);
        vector<int> diag(2, 0);
        for (int r1 = r; r1 < r + 3; ++r1) {
          for (int c1 = c; c1 < c + 3; ++c1) {
            ++cnt[grid[r1][c1]];
            row[r1 - r] += grid[r1][c1];
            col[c1 - c] += grid[r1][c1];
            if (r1 - r == c1 - c) { diag[0] += grid[r1][c1]; }
            if (r1 - r + c1 - c == 2) { diag[1] += grid[r1][c1]; }
          }
        }
        bool good = true;
        for (int n = 1; n <= 9; ++n) {
          if (cnt[n] != 1) {
            good = false;
            break;
          }
        }
        if (!good) { continue; }
        int sum = row[0];
        for (int r1 = 0; r1 < 3; ++r1) {
          if (row[r1] != sum) {
            good = false;
            break;
          }
        }
        if (!good) { continue; }
        for (int c1 = 0; c1 < 3; ++c1) {
          if (col[c1] != sum) {
            good = false;
            break;
          }
        }
        if (!good) { continue; }
        for (int d1 = 0; d1 < 2; ++d1) {
          if (diag[d1] != sum) {
            good = false;
            break;
          }
        }
        if (!good) { continue; }
        ++ans;
      }
    }
    return ans;
  }
};
