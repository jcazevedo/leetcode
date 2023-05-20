// 221. Maximal Square
// https://leetcode.com/problems/maximal-square/

#include <vector>

using namespace std;

class Solution {
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int N = matrix.size();
    if (N == 0)
      return 0;
    int M = matrix[0].size();
    vector<vector<int>> sums(N, vector<int>(M, 0));
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        int sum_up = i > 0 ? sums[i - 1][j] : 0;
        int sum_left = j > 0 ? sums[i][j - 1] : 0;
        int rep_sum = i > 0 && j > 0 ? sums[i - 1][j - 1] : 0;
        sums[i][j] = sum_left + sum_up - rep_sum;
        if (matrix[i][j] == '1')
          sums[i][j]++;
      }
    }
    int best = 0;
    int MAX_SIDE = min(N, M);
    for (int l = 1; l <= MAX_SIDE; ++l) {
      for (int i = 0; i + l <= N; ++i) {
        for (int j = 0; j + l <= M; ++j) {
          int sum_up = i > 0 ? sums[i - 1][j + l - 1] : 0;
          int sum_left = j > 0 ? sums[i + l - 1][j - 1] : 0;
          int rep_sum = i > 0 && j > 0 ? sums[i - 1][j - 1] : 0;
          int square = sums[i + l - 1][j + l - 1] - sum_up - sum_left + rep_sum;
          if (square == l * l)
            best = max(best, square);
        }
      }
    }
    return best;
  }
};
