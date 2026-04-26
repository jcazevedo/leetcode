// 1559. Detect Cycles in 2D Grid
// https://leetcode.com/problems/detect-cycles-in-2d-grid/

#include <vector>

using namespace std;

class Solution {
 private:
  bool dfs(
      char c, int i, int j, int pi, int pj, int m, int n, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
    visited[i][j] = true;
    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, -1, 1};
    for (int k = 0; k < 4; k++) {
      int ni = i + di[k];
      int nj = j + dj[k];
      if (ni < 0 || ni >= m || nj < 0 || nj >= n) { continue; }
      if (ni == pi && nj == pj) { continue; }
      if (grid[ni][nj] != c) { continue; }
      if (visited[ni][nj]) { return true; }
      if (dfs(c, ni, nj, i, j, m, n, grid, visited)) { return true; }
    }
    return false;
  }

 public:
  bool containsCycle(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (!visited[i][j]) {
          if (dfs(grid[i][j], i, j, -1, -1, m, n, grid, visited)) { return true; }
        }
      }
    }
    return false;
  }
};
