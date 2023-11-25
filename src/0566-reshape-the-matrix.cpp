// 566. Reshape the Matrix
// https://leetcode.com/problems/reshape-the-matrix/

#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    int H = mat.size();
    int W = mat[0].size();
    if (r * c != H * W) return mat;
    vector<vector<int>> ans(r, vector<int>(c, 0));
    int ni = 0, nj = 0;
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        ans[ni][nj] = mat[i][j];
        nj++;
        if (nj >= c) {
          nj = 0;
          ni++;
        }
      }
    }
    return ans;
  }
};
