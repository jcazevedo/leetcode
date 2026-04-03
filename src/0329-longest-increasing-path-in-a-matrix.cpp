// 329. Longest Increasing Path in a Matrix
// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

class Solution {
 public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> memo(m, vector<int>(n, 0));
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    function<int(int, int)> dfs = [&](int r, int c) -> int {
      if (memo[r][c] != 0) { return memo[r][c]; }
      int best = 1;
      for (int d = 0; d < 4; d++) {
        int nr = r + dx[d], nc = c + dy[d];
        if (nr >= 0 && nr < m && nc >= 0 && nc < n && matrix[nr][nc] > matrix[r][c]) {
          best = max(best, 1 + dfs(nr, nc));
        }
      }
      return memo[r][c] = best;
    };
    int ans = 0;
    for (int r = 0; r < m; r++) {
      for (int c = 0; c < n; c++) { ans = max(ans, dfs(r, c)); }
    }
    return ans;
  }
};
