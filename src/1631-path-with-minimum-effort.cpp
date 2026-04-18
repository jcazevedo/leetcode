// 1631. Path With Minimum Effort
// https://leetcode.com/problems/path-with-minimum-effort/

#include <algorithm>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumEffortPath(vector<vector<int>>& heights) {
    int H = heights.size(), W = heights[0].size();
    vector<vector<int>> dist(H, vector<int>(W, numeric_limits<int>::max()));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    dist[0][0] = 0;
    pq.push(make_pair(0, make_pair(0, 0)));
    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, -1, 1};
    while (!pq.empty()) {
      pair<int, pair<int, int>> curr = pq.top();
      pq.pop();
      int currDist = curr.first;
      int i = curr.second.first;
      int j = curr.second.second;
      if (i == H - 1 && j == W - 1) { return currDist; }
      if (currDist > dist[i][j]) { continue; }
      for (int d = 0; d < 4; ++d) {
        int ni = i + di[d];
        int nj = j + dj[d];
        if (ni < 0 || ni >= H || nj < 0 || nj >= W) { continue; }
        int nextDist = max(currDist, abs(heights[ni][nj] - heights[i][j]));
        if (nextDist < dist[ni][nj]) {
          dist[ni][nj] = nextDist;
          pq.push(make_pair(nextDist, make_pair(ni, nj)));
        }
      }
    }
    return dist[H - 1][W - 1];
  }
};
