// 51. N-Queens
// https://leetcode.com/problems/n-queens/

#include <string>
#include <vector>

using namespace std;

class Solution {
 private:
  void solve(int r,
             int n,
             vector<bool>& c,
             vector<bool>& d1,
             vector<bool>& d2,
             vector<string>& board,
             vector<vector<string>>& ans) {
    if (r == n) ans.push_back(board);
    for (int i = 0; i < n; ++i)
      if (!c[i] && !d1[i - r + n - 1] && !d2[i + r]) {
        c[i] = d1[i - r + n - 1] = d2[i + r] = true;
        board[r][i] = 'Q';
        solve(r + 1, n, c, d1, d2, board, ans);
        c[i] = d1[i - r + n - 1] = d2[i + r] = false;
        board[r][i] = '.';
      }
  }

 public:
  vector<vector<string>> solveNQueens(int n) {
    vector<bool> c(n, false);
    vector<bool> d1(2 * n - 1, false);
    vector<bool> d2(2 * n - 1, false);
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;
    solve(0, n, c, d1, d2, board, ans);
    return ans;
  }
};
