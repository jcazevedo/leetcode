// 934. Shortest Bridge
// https://leetcode.com/problems/shortest-bridge/

#include <queue>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
 private:
  static vector<vector<int>> directions;

  void floodFill(
      int i, int j, const vector<vector<int>>& grid, int H, int W, vector<vector<int>>& island, int currIsland) {
    island[i][j] = currIsland;
    for (const vector<int>& dir : directions) {
      int ni = i + dir[0];
      int nj = j + dir[1];
      if (ni >= 0 && ni < H && nj >= 0 && nj < W && grid[ni][nj] == 1 && island[ni][nj] == -1)
        floodFill(ni, nj, grid, H, W, island, currIsland);
    }
  }

 public:
  int shortestBridge(vector<vector<int>>& grid) {
    int H = grid.size();
    int W = grid[0].size();
    vector<vector<int>> island = vector<vector<int>>(H, vector<int>(W, -1));
    int nIslands = 0;
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        if (grid[i][j] == 1 && island[i][j] == -1) floodFill(i, j, grid, H, W, island, nIslands++);
      }
    }
    queue<tuple<int, int, int>> q;
    vector<vector<bool>> visited = vector<vector<bool>>(H, vector<bool>(W, false));
    for (int i = 0; i < H; ++i)
      for (int j = 0; j < W; ++j)
        if (island[i][j] == 0) q.push({0, i, j});
    while (!q.empty()) {
      int dist, i, j;
      tie(dist, i, j) = q.front();
      q.pop();
      for (const vector<int>& dir : directions) {
        int ni = i + dir[0];
        int nj = j + dir[1];
        if (ni >= 0 && ni < H && nj >= 0 && nj < W) {
          if (grid[ni][nj] == 0 && !visited[ni][nj]) {
            visited[ni][nj] = true;
            q.push({dist + 1, ni, nj});
          }
          if (grid[ni][nj] == 1 && island[ni][nj] == 1) return dist;
        }
      }
    }
    return -1;
  }
};

vector<vector<int>> Solution::directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
