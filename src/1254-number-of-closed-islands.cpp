// 1254. Number of Closed Islands
// https://leetcode.com/problems/number-of-closed-islands/

#include <vector>

using namespace std;

class Solution {
 private:
  int H, W;
  vector<vector<bool>> visited;

  bool is_closed(vector<vector<int>>& grid, int i, int j) {
    visited[i][j] = true;
    bool closed = true;

    if (i - 1 < 0)
      closed = false;
    else if (!visited[i - 1][j] && grid[i - 1][j] == 0)
      closed = is_closed(grid, i - 1, j) && closed;

    if (j - 1 < 0)
      closed = false;
    else if (!visited[i][j - 1] && grid[i][j - 1] == 0)
      closed = is_closed(grid, i, j - 1) && closed;

    if (i + 1 >= H)
      closed = false;
    else if (!visited[i + 1][j] && grid[i + 1][j] == 0)
      closed = is_closed(grid, i + 1, j) && closed;

    if (j + 1 >= W)
      closed = false;
    else if (!visited[i][j + 1] && grid[i][j + 1] == 0)
      closed = is_closed(grid, i, j + 1) && closed;

    return closed;
  }

 public:
  int closedIsland(vector<vector<int>>& grid) {
    H = grid.size();
    W = grid[0].size();
    visited = vector<vector<bool>>(H, vector<bool>(W, false));

    int ans = 0;

    for (int i = 0; i < H; ++i)
      for (int j = 0; j < W; ++j)
        if (!visited[i][j] && grid[i][j] == 0 && is_closed(grid, i, j)) ++ans;

    return ans;
  }
};
