// 407. Trapping Rain Water II
// https://leetcode.com/problems/trapping-rain-water-ii/

#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int trapRainWater(vector<vector<int>>& heightMap) {
    int H = heightMap.size(), W = heightMap[0].size();
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    for (int i = 0; i < H; ++i) {
      pq.push({heightMap[i][0], i, 0});
      visited[i][0] = true;
      pq.push({heightMap[i][W - 1], i, W - 1});
      visited[i][W - 1] = true;
      if (i == 0 || i == H - 1) {
        for (int j = 1; j < W - 1; ++j) {
          pq.push({heightMap[i][j], i, j});
          visited[i][j] = true;
        }
      }
    }
    int ans = 0;
    while (!pq.empty()) {
      vector<int> curr = pq.top();
      pq.pop();
      int h = curr[0];
      int i = curr[1];
      int j = curr[2];
      for (int di = -1; di <= 1; ++di) {
        int ni = i + di;
        if (ni < 0 || ni >= H) { continue; }
        for (int dj = -1; dj <= 1; ++dj) {
          if (abs(di) + abs(dj) != 1) { continue; }
          int nj = j + dj;
          if (nj < 0 || nj >= W) { continue; }
          if (visited[ni][nj]) { continue; }
          int nextHeight = heightMap[ni][nj];
          if (nextHeight < h) { ans += h - nextHeight; }
          visited[ni][nj] = true;
          pq.push({max(h, nextHeight), ni, nj});
        }
      }
    }
    return ans;
  }
};
