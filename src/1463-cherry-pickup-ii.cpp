// 1463. Cherry Pickup II
// https://leetcode.com/problems/cherry-pickup-ii/

#include <vector>

using namespace std;

#define IMPOSSIBLE -2
#define UNSET -1

class Solution {
private:
  vector<vector<vector<int>>> cache;
  vector<vector<int>> _grid;
  int R, C;

  int max_pickup(int row, int col_0, int col_1) {
    if (row < 0 || row >= R || col_0 < 0 || col_0 >= C || col_1 < 0 ||
        col_1 >= C) {
      return IMPOSSIBLE;
    }
    if (cache[row][col_0][col_1] == UNSET) {
      int curr = 0;
      curr += _grid[row][col_0];
      if (col_1 != col_0)
        curr += _grid[row][col_1];
      if (col_0 > row || C - col_1 - 1 > row) {
        cache[row][col_0][col_1] = IMPOSSIBLE;
      } else if (row == 0) {
        cache[row][col_0][col_1] = curr;
      } else {
        int best = IMPOSSIBLE;
        for (int d0 = -1; d0 <= 1; ++d0) {
          for (int d1 = -1; d1 <= 1; ++d1) {
            int next = max_pickup(row - 1, col_0 + d0, col_1 + d1);
            if (next == IMPOSSIBLE)
              continue;
            best = max(best, curr + next);
          }
        }
        cache[row][col_0][col_1] = best;
      }
    }
    return cache[row][col_0][col_1];
  }

public:
  int cherryPickup(vector<vector<int>>& grid) {
    _grid = grid;
    R = grid.size();
    C = grid[0].size();
    cache = vector<vector<vector<int>>>(
        R, vector<vector<int>>(C, vector<int>(C, UNSET)));
    int ans = 0;
    for (int i = 0; i < C; ++i) {
      for (int j = 0; j < C; ++j) {
        ans = max(ans, max_pickup(R - 1, i, j));
      }
    }
    return ans;
  }
};
