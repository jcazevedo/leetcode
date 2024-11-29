// 2577. Minimum Time to Visit a Cell In a Grid
// https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/

#include <algorithm>
#include <cmath>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumTime(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dist(m, vector<int>(n, numeric_limits<int>::max()));
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 0;
    while (!q.empty()) {
      pair<int, int> curr = q.front();
      q.pop();
      int i = curr.first;
      int j = curr.second;
      int d = dist[i][j];
      bool neigh = false;
      for (int di = -1; di <= 1; ++di) {
        int ni = i + di;
        if (ni < 0 || ni >= m) { continue; }
        for (int dj = -1; dj <= 1; ++dj) {
          int nj = j + dj;
          if (nj < 0 || nj >= n) { continue; }
          if (abs(di) + abs(dj) != 1) { continue; }
          int nd = d + 1;
          if (grid[ni][nj] <= nd) { neigh = true; }
        }
      }
      for (int di = -1; di <= 1; ++di) {
        int ni = i + di;
        if (ni < 0 || ni >= m) { continue; }
        for (int dj = -1; dj <= 1; ++dj) {
          int nj = j + dj;
          if (nj < 0 || nj >= n) { continue; }
          if (abs(di) + abs(dj) != 1) { continue; }
          int nd = d + 1;
          if (nd < grid[ni][nj]) {
            if (!neigh) { continue; }
            nd = d + (grid[ni][nj] - d) / 2 * 2 + 1;
          }
          if (nd < dist[ni][nj]) {
            dist[ni][nj] = nd;
            q.push({ni, nj});
          }
        }
      }
    }
    if (dist[m - 1][n - 1] == numeric_limits<int>::max()) { return -1; }
    return dist[m - 1][n - 1];
  }
};
