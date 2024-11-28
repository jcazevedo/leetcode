// 2290. Minimum Obstacle Removal to Reach Corner
// https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/

#include <algorithm>
#include <cmath>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumObstacles(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> minRemoved(m, vector<int>(n, numeric_limits<int>::max()));
    minRemoved[0][0] = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty()) {
      pair<int, int> curr = q.front();
      q.pop();
      int i = curr.first;
      int j = curr.second;
      for (int di = -1; di <= 1; ++di) {
        for (int dj = -1; dj <= 1; ++dj) {
          if (abs(di) + abs(dj) != 1) { continue; }
          int ni = i + di;
          int nj = j + dj;
          if (ni < 0 || ni >= m || nj < 0 || nj >= n) { continue; }
          if (grid[ni][nj] == 0 && minRemoved[ni][nj] > minRemoved[i][j]) {
            minRemoved[ni][nj] = minRemoved[i][j];
            q.push({ni, nj});
          }
          if (grid[ni][nj] == 1 && minRemoved[ni][nj] > minRemoved[i][j] + 1) {
            minRemoved[ni][nj] = minRemoved[i][j] + 1;
            q.push({ni, nj});
          }
        }
      }
    }
    return minRemoved[m - 1][n - 1];
  }
};
