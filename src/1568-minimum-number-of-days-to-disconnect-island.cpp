// 1568. Minimum Number of Days to Disconnect Island
// https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/

#include <cmath>
#include <vector>

using namespace std;

class Solution {
 private:
  void floodFill(int r, int c, int R, int C, vector<vector<bool>>& visited, const vector<vector<int>>& grid) {
    for (int dr = -1; dr <= 1; ++dr) {
      for (int dc = -1; dc <= 1; ++dc) {
        if (abs(dr) + abs(dc) != 1) { continue; }
        int nr = r + dr;
        int nc = c + dc;
        if (nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] == 1 && !visited[nr][nc]) {
          visited[nr][nc] = true;
          floodFill(nr, nc, R, C, visited, grid);
        }
      }
    }
  }

 public:
  int minDays(vector<vector<int>>& grid) {
    int R = grid.size();
    int C = grid[0].size();
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    int nIslands = 0;
    for (int r = 0; r < R; ++r) {
      for (int c = 0; c < C; ++c) {
        if (grid[r][c] == 1 && !visited[r][c]) {
          ++nIslands;
          visited[r][c] = true;
          floodFill(r, c, R, C, visited, grid);
        }
      }
    }
    if (nIslands != 1) { return 0; }
    for (int delR = 0; delR < R; ++delR) {
      for (int delC = 0; delC < C; ++delC) {
        if (grid[delR][delC] != 1) { continue; }
        grid[delR][delC] = 0;
        nIslands = 0;
        for (int r = 0; r < R; ++r) {
          for (int c = 0; c < C; ++c) { visited[r][c] = false; }
        }
        for (int r = 0; r < R; ++r) {
          for (int c = 0; c < C; ++c) {
            if (grid[r][c] == 1 && !visited[r][c]) {
              ++nIslands;
              visited[r][c] = true;
              floodFill(r, c, R, C, visited, grid);
            }
          }
        }
        if (nIslands != 1) { return 1; }
        grid[delR][delC] = 1;
      }
    }
    return 2;
  }
};
