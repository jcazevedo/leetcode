// 2257. Count Unguarded Cells in the Grid
// https://leetcode.com/problems/count-unguarded-cells-in-the-grid/

#include <vector>

using namespace std;

#define GUARD 1
#define WALL 2
#define GUARDED 3
#define UNGUARDED 4

class Solution {
 public:
  int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
    vector<vector<int>> grid = vector<vector<int>>(m, vector<int>(n, UNGUARDED));
    for (const vector<int>& guard : guards) { grid[guard[0]][guard[1]] = GUARD; }
    for (const vector<int>& wall : walls) { grid[wall[0]][wall[1]] = WALL; }
    for (int i = 0; i < m; ++i) {
      bool inGuard = false;
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == GUARD) {
          inGuard = true;
        } else if (grid[i][j] == WALL) {
          inGuard = false;
        } else if (inGuard) {
          grid[i][j] = GUARDED;
        }
      }
      inGuard = false;
      for (int j = n - 1; j >= 0; --j) {
        if (grid[i][j] == GUARD) {
          inGuard = true;
        } else if (grid[i][j] == WALL) {
          inGuard = false;
        } else if (inGuard) {
          grid[i][j] = GUARDED;
        }
      }
    }
    for (int j = 0; j < n; ++j) {
      bool inGuard = false;
      for (int i = 0; i < m; ++i) {
        if (grid[i][j] == GUARD) {
          inGuard = true;
        } else if (grid[i][j] == WALL) {
          inGuard = false;
        } else if (inGuard) {
          grid[i][j] = GUARDED;
        }
      }
      inGuard = false;
      for (int i = m - 1; i >= 0; --i) {
        if (grid[i][j] == GUARD) {
          inGuard = true;
        } else if (grid[i][j] == WALL) {
          inGuard = false;
        } else if (inGuard) {
          grid[i][j] = GUARDED;
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == UNGUARDED) { ++ans; }
      }
    }
    return ans;
  }
};
