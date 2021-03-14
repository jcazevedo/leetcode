#include <vector>

using namespace std;

class Solution {
private:
  vector<pair<int, int>> dirs = {{1, 0},
                                 {0, 1},
                                 {-1, 0},
                                 {0, -1}};

  vector<vector<int>> _grid;
  vector<vector<bool>> visited;
  int H, W;

  int get_perimeter(int i, int j) {
    int cnt = 0;
    visited[i][j] = true;
    for (pair<int, int> dir : dirs) {
      int ni = i + dir.first;
      int nj = j + dir.second;
      if (ni < 0 || ni >= H || nj < 0 || nj >= W)
        cnt++;
      else if (_grid[ni][nj] == 0)
        cnt++;
      else if (!visited[ni][nj])
        cnt += get_perimeter(ni, nj);
    }
    return cnt;
  }

public:
  int islandPerimeter(vector<vector<int>>& grid) {
    H = grid.size();
    W = grid[0].size();
    visited.assign(H, vector<bool>(W, false));
    _grid = grid;
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        if (grid[i][j] == 1)
          return get_perimeter(i, j);
      }
    }
    return 0;
  }
};
