// 959. Regions Cut By Slashes
// https://leetcode.com/problems/regions-cut-by-slashes/

#include <cmath>
#include <string>
#include <vector>

using namespace std;

class Solution {
 private:
  void floodFill(int i, int j, int N, const vector<string>& grid, vector<vector<bool>>& visited) {
    for (int di = -1; di <= 1; ++di) {
      for (int dj = -1; dj <= 1; ++dj) {
        if (abs(di) + abs(dj) != 1) { continue; }
        int ni = i + di;
        int nj = j + dj;
        if (ni >= 0 && ni < N && nj >= 0 && nj < N && !visited[ni][nj]) {
          visited[ni][nj] = true;
          floodFill(ni, nj, N, grid, visited);
        }
      }
    }
  }

 public:
  int regionsBySlashes(vector<string>& grid) {
    int N = grid.size() * 3;
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    for (int i = 0; i < N / 3; ++i) {
      for (int j = 0; j < N / 3; ++j) {
        if (grid[i][j] == '/') {
          visited[i * 3][j * 3 + 2] = true;
          visited[i * 3 + 1][j * 3 + 1] = true;
          visited[i * 3 + 2][j * 3] = true;
        }
        if (grid[i][j] == '\\') {
          visited[i * 3][j * 3] = true;
          visited[i * 3 + 1][j * 3 + 1] = true;
          visited[i * 3 + 2][j * 3 + 2] = true;
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (!visited[i][j]) {
          ++ans;
          visited[i][j] = true;
          floodFill(i, j, N, grid, visited);
        }
      }
    }
    return ans;
  }
};
