// 1905. Count Sub Islands
// https://leetcode.com/problems/count-sub-islands/

#include <cmath>
#include <vector>

using namespace std;

class Solution {
 private:
  bool good(int r,
            int c,
            int R,
            int C,
            const vector<vector<int>>& grid1,
            const vector<vector<int>>& grid2,
            vector<vector<bool>>& visited) {
    bool ans = true;
    if (grid1[r][c] == 0) { ans = false; }
    for (int dr = -1; dr <= 1; ++dr) {
      for (int dc = -1; dc <= 1; ++dc) {
        if (abs(dr) + abs(dc) != 1) { continue; }
        int nr = r + dr;
        int nc = c + dc;
        if (nr >= 0 && nr < R && nc >= 0 && nc < C && !visited[nr][nc] && grid2[nr][nc] == 1) {
          visited[nr][nc] = true;
          if (!good(nr, nc, R, C, grid1, grid2, visited)) { ans = false; }
        }
      }
    }
    return ans;
  }

 public:
  int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    int R = grid1.size(), C = grid1[0].size(), ans = 0;
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    for (int r = 0; r < R; ++r) {
      for (int c = 0; c < C; ++c) {
        if (!visited[r][c] && grid2[r][c] == 1) {
          visited[r][c] = true;
          if (good(r, c, R, C, grid1, grid2, visited)) { ++ans; }
        }
      }
    }
    return ans;
  }
};
