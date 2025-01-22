// 1765. Map of Highest Peak
// https://leetcode.com/problems/map-of-highest-peak/

#include <queue>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
 private:
  static vector<vector<int>> dirs;

 public:
  vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    int H = isWater.size(), W = isWater[0].size();
    vector<vector<int>> dist(H, vector<int>(W, H * W));
    queue<tuple<int, int>> q;
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        if (isWater[i][j] == 1) {
          dist[i][j] = 0;
          q.push({i, j});
        }
      }
    }
    int i, j;
    while (!q.empty()) {
      tie(i, j) = q.front();
      q.pop();
      for (const vector<int>& dir : dirs) {
        int ni = i + dir[0];
        int nj = j + dir[1];
        if (ni >= 0 && ni < H && nj >= 0 && nj < W && dist[i][j] + 1 < dist[ni][nj]) {
          dist[ni][nj] = dist[i][j] + 1;
          q.push({ni, nj});
        }
      }
    }
    return dist;
  }
};

vector<vector<int>> Solution::dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
