// 1091. Shortest Path in Binary Matrix
// https://leetcode.com/problems/shortest-path-in-binary-matrix/

#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int H = grid.size();
    if (H == 0) return -1;
    int W = grid[0].size();
    if (W == 0 || grid[0][0] != 0) return -1;
    vector<vector<int>> dist(H, vector<int>(W, -1));
    vector<pair<int, int>> dirs = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
    dist[0][0] = 1;
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty()) {
      pair<int, int> curr = q.front();
      q.pop();
      for (pair<int, int> dir : dirs) {
        int ni = curr.first + dir.first;
        int nj = curr.second + dir.second;
        if (ni < 0 || ni >= H || nj < 0 || nj >= W || grid[ni][nj] == 1 || dist[ni][nj] != -1) continue;
        dist[ni][nj] = dist[curr.first][curr.second] + 1;
        q.push({ni, nj});
      }
    }
    return dist[H - 1][W - 1];
  }
};
