// 1391. Check if There is a Valid Path in a Grid
// https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 private:
  int di[4] = {-1, 1, 0, 0};
  int dj[4] = {0, 0, -1, 1};
  unordered_map<int, vector<vector<int>>> next = {
      {1, {{}, {}, {1, 4, 6}, {1, 3, 5}}}, {2, {{2, 3, 4}, {2, 5, 6}, {}, {}}}, {3, {{}, {2, 5, 6}, {1, 4, 6}, {}}},
      {4, {{}, {2, 5, 6}, {}, {1, 3, 5}}}, {5, {{2, 3, 4}, {}, {1, 4, 6}, {}}}, {6, {{2, 3, 4}, {}, {}, {1, 3, 5}}}};

  bool dfs(int i, int j, int ti, int tj, int m, int n, const vector<vector<int>>& grid, vector<vector<bool>>& visited) {
    if (i == ti && j == tj) { return true; }
    visited[i][j] = true;
    for (int d = 0; d < 4; ++d) {
      int ni = i + di[d];
      int nj = j + dj[d];
      if (ni < 0 || ni >= m || nj < 0 || nj >= n) { continue; }
      if (visited[ni][nj]) { continue; }
      bool valid = false;
      for (int p = 0; p < (int)next[grid[i][j]][d].size(); ++p) {
        if (next[grid[i][j]][d][p] == grid[ni][nj]) {
          valid = true;
          break;
        }
      }
      if (!valid) { continue; }
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
