// 1572. Matrix Diagonal Sum
// https://leetcode.com/problems/matrix-diagonal-sum/

#include <vector>

using namespace std;

class Solution {
public:
  int diagonalSum(vector<vector<int>>& mat) {
    int N = mat.size();
    int ans = 0;
    for (int i = 0; i < N; ++i) {
      ans += mat[i][i];
      ans += mat[i][N - i - 1];
    }
    if (N % 2 != 0)
      ans -= mat[N / 2][N / 2];
    return ans;
  }
};
