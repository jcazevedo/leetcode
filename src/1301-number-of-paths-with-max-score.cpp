// 1301. Number of Paths with Max Score
// https://leetcode.com/problems/number-of-paths-with-max-score/

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define MOD 1000000007

class Solution {
 public:
  vector<int> pathsWithMaxScore(vector<string>& board) {
    int n = board.size();
    int dr[3] = {1, 0, 1};
    int dc[3] = {0, 1, 1};
    vector<vector<int>> best(n, vector<int>(n, -1));
    vector<vector<int>> ways(n, vector<int>(n, 0));
    best[n - 1][n - 1] = 0;
    ways[n - 1][n - 1] = 1;
    for (int r = n - 1; r >= 0; --r) {
      for (int c = n - 1; c >= 0; --c) {
        if (board[r][c] == 'X' || (r == n - 1 && c == n - 1)) { continue; }
        int next_best = -1;
        for (int d = 0; d < 3; ++d) {
          int nr = r + dr[d];
          int nc = c + dc[d];
          if (nr >= n || nc >= n || best[nr][nc] == -1) { continue; }
          next_best = max(next_best, best[nr][nc]);
        }
        if (next_best == -1) { continue; }
        long long count = 0;
        for (int d = 0; d < 3; ++d) {
          int nr = r + dr[d];
          int nc = c + dc[d];
          if (nr >= n || nc >= n || best[nr][nc] != next_best) { continue; }
          count = (count + ways[nr][nc]) % MOD;
        }
        int value = board[r][c] >= '0' && board[r][c] <= '9' ? board[r][c] - '0' : 0;
        best[r][c] = next_best + value;
        ways[r][c] = count;
      }
    }
    if (best[0][0] == -1) { return {0, 0}; }
    return {best[0][0], ways[0][0]};
  }
};
