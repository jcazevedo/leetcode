// 1293. Shortest Path in a Grid with Obstacles Elimination
// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/

#include <algorithm>
#include <cstring>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 private:
  static vector<vector<int>> dirs;

 public:
  int shortestPath(vector<vector<int>>& grid, int k) {
    int m = grid.size(), n = grid[0].size();
    if (m == 1 && n == 1) { return 0; }
    int dist[m][n][k + 1];
    memset(dist, -1, sizeof(dist));
    queue<vector<int>> q;
    dist[0][0][k] = 0;
    q.push({0, 0, k});
    int ans = numeric_limits<int>::max();
    while (!q.empty()) {
      vector<int> curr = q.front();
      q.pop();
      int currI = curr[0];
      int currJ = curr[1];
      int currK = curr[2];
      for (const vector<int>& dir : dirs) {
        int nextI = currI + dir[0];
        int nextJ = currJ + dir[1];
        if (nextI >= 0 && nextI < m && nextJ >= 0 && nextJ < n) {
          int nextDist = dist[currI][currJ][currK] + 1;
          if (nextDist > ans) { continue; }
          if (grid[nextI][nextJ] == 0 || currK > 0) {
            if (nextI == m - 1 && nextJ == n - 1) { ans = min(ans, nextDist); }
            int nextK = currK - (grid[nextI][nextJ] == 1 ? 1 : 0);
            vector<int> next = {nextI, nextJ, nextK};
            if (dist[nextI][nextJ][nextK] == -1 || dist[nextI][nextJ][nextK] > nextDist) {
              dist[nextI][nextJ][nextK] = nextDist;
              q.push(next);
            }
          }
        }
      }
    }
    return ans == numeric_limits<int>::max() ? -1 : ans;
  }
};

vector<vector<int>> Solution::dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
