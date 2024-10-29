// 2684. Maximum Number of Moves in a Grid
// https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxMoves(vector<vector<int>>& grid) {
    int H = grid.size();
    int W = grid[0].size();
    vector<vector<int>> dp(H, vector<int>(W, 0));
    for (int w = W - 1; w >= 0; --w) {
      for (int h = H - 1; h >= 0; --h) {
        if (h - 1 >= 0 && w + 1 < W && grid[h - 1][w + 1] > grid[h][w]) {
          dp[h][w] = max(dp[h][w], dp[h - 1][w + 1] + 1);
        }
        if (w + 1 < W && grid[h][w + 1] > grid[h][w]) { dp[h][w] = max(dp[h][w], dp[h][w + 1] + 1); }
        if (h + 1 < H && w + 1 < W && grid[h + 1][w + 1] > grid[h][w]) {
          dp[h][w] = max(dp[h][w], dp[h + 1][w + 1] + 1);
        }
      }
    }
    int ans = 0;
    for (int h = 0; h < H; ++h) { ans = max(ans, dp[h][0]); }
    return ans;
  }
};
