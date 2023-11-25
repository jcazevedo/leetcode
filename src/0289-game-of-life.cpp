// 289. Game of Life
// https://leetcode.com/problems/game-of-life/

#include <vector>

using namespace std;

class Solution {
public:
  void gameOfLife(vector<vector<int>>& board) {
    int M = board.size(), N = board[0].size();
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        int neigh = 0;
        for (int di = -1; di <= 1; ++di) {
          for (int dj = -1; dj <= 1; ++dj) {
            int ni = i + di;
            int nj = j + dj;
            neigh += (ni != i || nj != j) && ni >= 0 && ni < M && nj >= 0 &&
                             nj < N && board[ni][nj] % 2
                         ? 1
                         : 0;
          }
        }
        board[i][j] =
            board[i][j] | (((board[i][j] % 2 && neigh >= 2 && neigh <= 3) ||
                            (board[i][j] % 2 == 0 && neigh == 3))
                               ? 2
                               : 0);
      }
    }
    for (int i = 0; i < M; ++i)
      for (int j = 0; j < N; ++j)
        board[i][j] /= 2;
  }
};
