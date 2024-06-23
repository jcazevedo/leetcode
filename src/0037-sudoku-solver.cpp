// 37. Sudoku Solver
// https://leetcode.com/problems/sudoku-solver/

#include <set>
#include <vector>

using namespace std;

class Solution {
 private:
  int sq(int i, int j) { return i / 3 + 3 * (j / 3); }

  bool solve(
      int i, int j, vector<vector<char>>& board, vector<set<char>>& r, vector<set<char>>& c, vector<set<char>>& s) {
    if (i == 9) { return true; }
    int ni = i;
    int nj = j + 1;
    if (nj >= 9) {
      ni++;
      nj = 0;
    }
    if (board[i][j] != '.') { return solve(ni, nj, board, r, c, s); }
    set<char> possible;
    for (char ch = '1'; ch <= '9'; ++ch) {
      if (r[i].find(ch) != r[i].end() && c[j].find(ch) != c[j].end() && s[sq(i, j)].find(ch) != s[sq(i, j)].end()) {
        possible.insert(ch);
      }
    }
    if (possible.empty()) { return false; }
    for (char ch : possible) {
      r[i].erase(ch);
      c[j].erase(ch);
      s[sq(i, j)].erase(ch);
      board[i][j] = ch;
      if (solve(ni, nj, board, r, c, s)) { return true; }
      board[i][j] = '.';
      r[i].insert(ch);
      c[j].insert(ch);
      s[sq(i, j)].insert(ch);
    }
    return false;
  }

 public:
  void solveSudoku(vector<vector<char>>& board) {
    vector<set<char>> r(9, set<char>());
    vector<set<char>> c(9, set<char>());
    vector<set<char>> s(9, set<char>());
    for (int i = 0; i < 9; ++i) {
      for (char ch = '1'; ch <= '9'; ++ch) {
        r[i].insert(ch);
        c[i].insert(ch);
        s[i].insert(ch);
      }
    }
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        r[i].erase(board[i][j]);
        c[j].erase(board[i][j]);
        s[sq(i, j)].erase(board[i][j]);
      }
    }
    solve(0, 0, board, r, c, s);
  }
};
