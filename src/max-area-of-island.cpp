#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 private:
  vector<vector<bool>> visited;
  int H, W;
  vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

  int fill(int h, int w, vector<vector<int>>& grid) {
    if (h < 0 || h >= H || w < 0 || w >= W || visited[h][w] || grid[h][w] == 0) return 0;
    visited[h][w] = true;
    int area = 1;
    for (int i = 0; i < 4; ++i) {
      int nh = h + dirs[i][0];
      int nw = w + dirs[i][1];
      area += fill(nh, nw, grid);
    }
    return area;
  }

 public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    H = grid.size();
    if (H == 0) return 0;
    W = grid[0].size();
    if (W == 0) return 0;
    visited.assign(H, vector<bool>(W, false));
    int max_area = 0;
    for (int h = 0; h < H; ++h) {
      for (int w = 0; w < W; ++w) {
        if (grid[h][w] == 1 && !visited[h][w]) max_area = max(max_area, fill(h, w, grid));
      }
    }
    return max_area;
  }
};
