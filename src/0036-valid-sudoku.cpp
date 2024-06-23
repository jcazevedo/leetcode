// 36. Valid Sudoku
// https://leetcode.com/problems/valid-sudoku/

#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    int N = board.size();
    for (int i = 0; i < N; ++i) {
      set<char> visited;
      for (int j = 0; j < N; ++j) {
        if (board[i][j] == '.') continue;
        if (visited.find(board[i][j]) != visited.end()) return false;
        visited.insert(board[i][j]);
      }
    }
    for (int j = 0; j < N; ++j) {
      set<char> visited;
      for (int i = 0; i < N; ++i) {
        if (board[i][j] == '.') continue;
        if (visited.find(board[i][j]) != visited.end()) return false;
        visited.insert(board[i][j]);
      }
    }
    for (int i = 0; i < N; i += 3) {
      for (int j = 0; j < N; j += 3) {
        set<char> visited;
        for (int di = 0; di < 3; ++di) {
          for (int dj = 0; dj < 3; ++dj) {
            if (board[i + di][j + dj] == '.') continue;
            if (visited.find(board[i + di][j + dj]) != visited.end()) return false;
            visited.insert(board[i + di][j + dj]);
          }
        }
      }
    }
    return true;
  }
};
