// 1368. Minimum Cost to Make at Least One Valid Path in a Grid
// https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/

#include <cmath>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  int minCost(vector<vector<int>>& grid) {
    int H = grid.size(), W = grid[0].size();
    vector<vector<int>> dist(H, vector<int>(W, numeric_limits<int>::max()));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    dist[0][0] = 0;
    pq.push(make_pair(0, make_pair(0, 0)));
    while (!pq.empty()) {
      pair<int, pair<int, int>> curr = pq.top();
      pq.pop();
      int currDist = curr.first;
      int i = curr.second.first;
      int j = curr.second.second;
      for (int di = -1; di <= 1; ++di) {
        int ni = i + di;
        if (ni < 0 || ni >= H) { continue; }
        for (int dj = -1; dj <= 1; ++dj) {
          int nj = j + dj;
          if (nj < 0 || nj >= W) { continue; }
          if (abs(di) + abs(dj) != 1) { continue; }
          int nextDist = currDist;
          if (ni == i && nj == j + 1 && grid[i][j] != 1) { nextDist += 1; }
          if (ni == i && nj == j - 1 && grid[i][j] != 2) { nextDist += 1; }
          if (ni == i + 1 && nj == j && grid[i][j] != 3) { nextDist += 1; }
          if (ni == i - 1 && nj == j && grid[i][j] != 4) { nextDist += 1; }
          if (nextDist < dist[ni][nj]) {
            dist[ni][nj] = nextDist;
            pq.push(make_pair(nextDist, make_pair(ni, nj)));
          }
        }
      }
    }
    return dist[H - 1][W - 1];
  }
};
