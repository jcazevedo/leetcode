// 688. Knight Probability in Chessboard
// https://leetcode.com/problems/knight-probability-in-chessboard/

#include <vector>

using namespace std;

class Solution {
private:
  static vector<vector<int>> directions;

public:
  double knightProbability(int n, int k, int row, int column) {
    vector<vector<vector<double>>> probability(k + 1, vector<vector<double>>(n, vector<double>(n, 0.0)));
    probability[0][row][column] = 1.0;
    for (int i = 1; i <= k; ++i) {
      for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
          for (unsigned int d = 0; d < directions.size(); ++d) {
            int nr = r + directions[d][0];
            int nc = c + directions[d][1];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
              probability[i][nr][nc] += probability[i - 1][r][c] / directions.size();
            }
          }
        }
      }
    }
    double ans = 0.0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        ans += probability[k][i][j];
      }
    }
    return ans;
  }
};

vector<vector<int>> Solution::directions = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};
