#include <vector>

using namespace std;

class Solution {
private:
  int H;
  int W;
  vector<vector<int>> dists;
  vector<vector<bool>> visited;
  int dirs[4][2] = {{0,  1},
                    {0,  -1},
                    {1,  0},
                    {-1, 0}};

  void dfs(vector<vector<int>>& grid, int i, int j, int s) {
    for (int d = 0; d < 4; ++d) {
      int ni = i + dirs[d][0];
      int nj = j + dirs[d][1];
      int ns = s + 1;
      if (ni >= 0 && ni < H && nj >= 0 && nj < W && grid[ni][nj] == 1 &&
          (dists[ni][nj] == -1 || dists[ni][nj] > ns)) {
        visited[ni][nj] = true;
        dists[ni][nj] = ns;
        dfs(grid, ni, nj, ns);
      }
    }
  }

public:
  int orangesRotting(vector<vector<int>>& grid) {
    H = grid.size();
    W = grid[0].size();
    dists.clear();
    dists.assign(H, vector<int>(W, -1));
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        if (grid[i][j] == 2) {
          dists[i][j] = 0;
          visited.clear();
          visited.assign(H, vector<bool>(W, false));
          visited[i][j] = true;
          dfs(grid, i, j, 0);
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        if (grid[i][j] == 1) {
          if (dists[i][j] == -1)
            return -1;
          ans = max(ans, dists[i][j]);
        }
      }
    }
    return ans;
  }
};
