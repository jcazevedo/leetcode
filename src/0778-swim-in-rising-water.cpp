// 778. Swim in Rising Water
// https://leetcode.com/problems/swim-in-rising-water/

#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  int swimInWater(vector<vector<int>>& grid) {
    int N = grid.size();
    vector<vector<int>> dist(N, vector<int>(N, -1));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    dist[0][0] = grid[0][0];
    pq.push(make_pair(grid[0][0], make_pair(0, 0)));
    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, -1, 1};
    while (!pq.empty()) {
      pair<int, pair<int, int>> curr = pq.top();
      pq.pop();
      int currDist = curr.first;
      int i = curr.second.first;
      int j = curr.second.second;
      if (i == N - 1 && j == N - 1) { return currDist; }
      if (currDist > dist[i][j]) { continue; }
      for (int d = 0; d < 4; ++d) {
        int ni = i + di[d];
        int nj = j + dj[d];
        if (ni < 0 || ni >= N || nj < 0 || nj >= N) { continue; }
        int nextDist = max(currDist, grid[ni][nj]);
        if (dist[ni][nj] == -1 || nextDist < dist[ni][nj]) {
          dist[ni][nj] = nextDist;
          pq.push(make_pair(nextDist, make_pair(ni, nj)));
        }
      }
    }
    return dist[N - 1][N - 1];
  }
};
