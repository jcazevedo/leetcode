// 980. Unique Paths III
// https://leetcode.com/problems/unique-paths-iii/

#include <vector>

using namespace std;

int dirs[][4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

class Solution {
 private:
  int dfs(int i,
          int j,
          vector<vector<int>>& grid,
          int H,
          int W,
          vector<vector<bool>>& visited,
          int expected,
          int n_visited) {
    if (grid[i][j] == 2) {
      if (n_visited == expected) return 1;
      return 0;
    }
    int ans = 0;
    for (int d = 0; d < 4; ++d) {
      int ni = i + dirs[d][0];
      int nj = j + dirs[d][1];
      if (ni >= 0 && ni < H && nj >= 0 && nj < W && grid[ni][nj] != -1 && !visited[ni][nj]) {
        visited[ni][nj] = true;
        ans += dfs(ni, nj, grid, H, W, visited, expected, n_visited + 1);
        visited[ni][nj] = false;
      }
    }
    return ans;
  }

 public:
  int uniquePathsIII(vector<vector<int>>& grid) {
    int H = grid.size();
    int W = grid[0].size();
    int expected = 0;
    int si, sj;
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        if (grid[i][j] != -1) expected++;
        if (grid[i][j] == 1) {
          si = i;
          sj = j;
        }
      }
    }
    vector<vector<bool>> visited = vector<vector<bool>>(H, vector<bool>(W, false));
    visited[si][sj] = true;
    return dfs(si, sj, grid, H, W, visited, expected, 1);
  }
};
