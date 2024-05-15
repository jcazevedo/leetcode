// 1219. Path with Maximum Gold
// https://leetcode.com/problems/path-with-maximum-gold/

#include <queue>
#include <vector>

using namespace std;

class Solution {
 private:
  static vector<vector<int>> dirs;

  int dfs(int i, int j, int M, int N, vector<vector<int>>& grid) {
    if (i < 0 || j < 0 || i >= M || j >= N || grid[i][j] == 0) return 0;

    int ans = 0, gold = grid[i][j];
    grid[i][j] = 0;
    for (const vector<int>& dir : dirs) {
      int ni = i + dir[0];
      int nj = j + dir[1];
      ans = max(ans, dfs(ni, nj, M, N, grid));
    }
    grid[i][j] = gold;

    return ans + gold;
  }

 public:
  int getMaximumGold(vector<vector<int>>& grid) {
    int M = grid.size(), N = grid[0].size(), ans = 0;

    for (int i = 0; i < M; ++i)
      for (int j = 0; j < N; ++j) ans = max(ans, dfs(i, j, M, N, grid));

    return ans;
  }
};

vector<vector<int>> Solution::dirs = {{0, -1}, {0, +1}, {-1, 0}, {+1, 0}};
