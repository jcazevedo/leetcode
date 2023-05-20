// 73. Set Matrix Zeroes
// https://leetcode.com/problems/set-matrix-zeroes/

#include <vector>

using namespace std;

class Solution {
public:
  void setZeroes(vector<vector<int>>& matrix) {
    int H = matrix.size();
    if (H == 0)
      return;
    int W = matrix[0].size();
    if (W == 0)
      return;
    bool zf = false;
    for (int i = 0; i < H; i++)
      if (matrix[i][0] == 0)
        zf = true;
    for (int j = 1; j < W; j++) {
      for (int i = 0; i < H; i++) {
        if (matrix[i][j] == 0) {
          for (int k = 0; k < H; k++) {
            if (matrix[k][j] == 0)
              matrix[k][0] = 0;
            matrix[k][j] = 0;
          }
          break;
        }
      }
    }
    for (int i = 0; i < H; i++) {
      if (matrix[i][0] == 0) {
        for (int j = 0; j < W; j++)
          matrix[i][j] = 0;
      }
    }
    if (zf) {
      for (int i = 0; i < H; i++)
        matrix[i][0] = 0;
    }
  }
};
