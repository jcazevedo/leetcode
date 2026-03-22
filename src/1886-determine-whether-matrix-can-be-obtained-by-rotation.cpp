// 1886. Determine Whether Matrix Can Be Obtained By Rotation
// https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/

#include <vector>

using namespace std;

class Solution {
 public:
  bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
    int n = mat.size();
    for (int r = 0; r < 4; ++r) {
      if (mat == target) { return true; }
      for (int i = 0; i < n / 2; ++i) {
        for (int j = i; j < n - 1 - i; ++j) {
          int tmp = mat[i][j];
          mat[i][j] = mat[n - 1 - j][i];
          mat[n - 1 - j][i] = mat[n - 1 - i][n - 1 - j];
          mat[n - 1 - i][n - 1 - j] = mat[j][n - 1 - i];
          mat[j][n - 1 - i] = tmp;
        }
      }
    }
    return false;
  }
};
