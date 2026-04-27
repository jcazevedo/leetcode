// 1391. Check if There is a Valid Path in a Grid
// https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/

#include <vector>

using namespace std;

class Solution {
 private:
  static constexpr int di[4] = {-1, 1, 0, 0};
  static constexpr int dj[4] = {0, 0, -1, 1};
  static constexpr bool exits[7][4] = {
      {false, false, false, false}, {false, false, true, true}, {true, true, false, false}, {false, true, true, false},
      {false, true, false, true},   {true, false, true, false}, {true, false, false, true},
  };

  bool dfs(int i, int j, int ti, int tj, int m, int n, const vector<vector<int>>& grid, vector<vector<bool>>& visited) {
    if (i == ti && j == tj) { return true; }
    visited[i][j] = true;
    for (int d = 0; d < 4; ++d) {
      if (!exits[grid[i][j]][d]) { continue; }
      int ni = i + di[d];
      int nj = j + dj[d];
      if (ni < 0 || ni >= m || nj < 0 || nj >= n) { continue; }
      if (visited[ni][nj]) { continue; }
      if (!exits[grid[ni][nj]][d ^ 1]) { continue; }
      if (dfs(ni, nj, ti, tj, m, n, grid, visited)) { return true; }
    }
    return false;
  }

 public:
  bool hasValidPath(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    return dfs(0, 0, m - 1, n - 1, m, n, grid, visited);
  }
};
