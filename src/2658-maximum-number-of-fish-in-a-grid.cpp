// 2658. Maximum Number of Fish in a Grid
// https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/

#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 private:
  int ff(int startI, int startJ, const vector<vector<int>>& grid, vector<vector<bool>>& visited) {
    int M = grid.size();
    int N = grid[0].size();
    queue<vector<int>> q;
    q.push({startI, startJ});
    visited[startI][startJ] = true;
    int ans = 0;
    while (!q.empty()) {
      vector<int> curr = q.front();
      q.pop();
      int i = curr[0];
      int j = curr[1];
      ans += grid[i][j];
      for (int di = -1; di <= 1; ++di) {
        int ni = i + di;
        if (ni < 0 || ni >= M) { continue; }
        for (int dj = -1; dj <= 1; ++dj) {
          if (abs(di) + abs(dj) != 1) { continue; }
          int nj = j + dj;
          if (nj < 0 || nj >= N || visited[ni][nj] || grid[ni][nj] == 0) { continue; }
          visited[ni][nj] = true;
          q.push({ni, nj});
        }
      }
    }
    return ans;
  }

 public:
  int findMaxFish(vector<vector<int>>& grid) {
    int M = grid.size();
    int N = grid[0].size();
    int ans = 0;
    vector<vector<bool>> visited(M, vector<bool>(N, false));
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        if (visited[i][j]) { continue; }
        if (grid[i][j] > 0) { ans = max(ans, ff(i, j, grid, visited)); }
      }
    }
    return ans;
  }
};
