// 130. Surrounded Regions
// https://leetcode.com/problems/surrounded-regions/

#include <vector>

using namespace std;

class Solution {
 private:
  int H, W;
  vector<vector<bool>> visited;
  vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  bool is_surrounded(int i, int j, vector<vector<char>>& board) {
    visited[i][j] = true;
    bool good = true;
    for (int d = 0; d < 4; ++d) {
      int ni = i + dirs[d].first;
      int nj = j + dirs[d].second;
      if (ni < 0 || ni >= H || nj < 0 || nj >= W) {
        good = good && false;
        continue;
      }
      if (board[ni][nj] == 'X' || visited[ni][nj]) continue;
      if (!is_surrounded(ni, nj, board)) good = good && false;
    }
    return good;
  }

  void flip(int i, int j, vector<vector<char>>& board) {
    board[i][j] = 'X';
    for (int d = 0; d < 4; ++d) {
      int ni = i + dirs[d].first;
      int nj = j + dirs[d].second;
      if (ni < 0 || ni >= H || nj < 0 || nj >= W || board[ni][nj] == 'X') continue;
      flip(ni, nj, board);
    }
  }

 public:
  void solve(vector<vector<char>>& board) {
    H = board.size();
    if (H == 0) return;
    W = board[0].size();
    if (W == 0) return;
    visited.assign(H, vector<bool>(W, false));
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        if (visited[i][j] || board[i][j] == 'X') continue;
        if (is_surrounded(i, j, board)) flip(i, j, board);
      }
    }
  }
};
