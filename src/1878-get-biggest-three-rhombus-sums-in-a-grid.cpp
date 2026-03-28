// 1878. Get Biggest Three Rhombus Sums in a Grid
// https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/

#include <functional>
#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> getBiggestThree(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> d1(m, vector<int>(n)), d2(m, vector<int>(n));
    for (int r = 0; r < m; r++) {
      for (int c = 0; c < n; c++) {
        d1[r][c] = grid[r][c] + (r > 0 && c > 0 ? d1[r - 1][c - 1] : 0);
        d2[r][c] = grid[r][c] + (r > 0 && c < n - 1 ? d2[r - 1][c + 1] : 0);
      }
    }
    function<int(int, int, int, int)> sumD1 = [&](int r1, int c1, int r2, int c2) {
      return d1[r2][c2] - (r1 > 0 && c1 > 0 ? d1[r1 - 1][c1 - 1] : 0);
    };
    function<int(int, int, int, int)> sumD2 = [&](int r1, int c1, int r2, int c2) {
      return d2[r2][c2] - (r1 > 0 && c1 < n - 1 ? d2[r1 - 1][c1 + 1] : 0);
    };
    set<int> top3;
    for (int r = 0; r < m; r++) {
      for (int c = 0; c < n; c++) {
        top3.insert(grid[r][c]);
        if (top3.size() > 3) { top3.erase(top3.begin()); }
        for (int s = 1; r + 2 * s < m && c - s >= 0 && c + s < n; s++) {
          int sum = sumD1(r, c, r + s, c + s) + sumD2(r, c, r + s, c - s) + sumD1(r + s, c - s, r + 2 * s, c) +
                    sumD2(r + s, c + s, r + 2 * s, c) - grid[r][c] - grid[r + s][c - s] - grid[r + s][c + s] -
                    grid[r + 2 * s][c];
          top3.insert(sum);
          if (top3.size() > 3) { top3.erase(top3.begin()); }
        }
      }
    }
    return vector<int>(top3.rbegin(), top3.rend());
  }
};
