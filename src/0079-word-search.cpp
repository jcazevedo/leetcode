// 79. Word Search
// https://leetcode.com/problems/word-search/

#include <string>
#include <vector>

using namespace std;

class Solution {
 private:
  vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  bool dfs(int i,
           int j,
           int idx,
           string word,
           const vector<vector<char>>& board,
           vector<vector<bool>>& visited,
           int H,
           int W) {
    if (idx >= (int)word.size() - 1) return true;
    visited[i][j] = true;
    for (pair<int, int> dir : dirs) {
      int ni = i + dir.first;
      int nj = j + dir.second;
      if (ni >= 0 && ni < H && nj >= 0 && nj < W && !visited[ni][nj] && board[ni][nj] == word[idx + 1] &&
          dfs(ni, nj, idx + 1, word, board, visited, H, W))
        return true;
    }
    visited[i][j] = false;
    return false;
  }

 public:
  bool exist(vector<vector<char>>& board, string word) {
    if (word.empty()) return true;
    int H = board.size();
    if (H == 0) return false;
    int W = board[0].size();
    vector<vector<bool>> visited;
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        if (board[i][j] == word[0]) {
          visited.assign(H, vector<bool>(W, false));
          if (dfs(i, j, 0, word, board, visited, H, W)) return true;
        }
      }
    }
    return false;
  }
};
