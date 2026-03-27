// 2946. Matrix Similarity After Cyclic Shifts
// https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/

#include <vector>

using namespace std;

class Solution {
 public:
  bool areSimilar(vector<vector<int>>& mat, int k) {
    int m = mat.size(), n = mat[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int tj;
        if (i % 2 == 0) {
          tj = (j + k) % n;
        } else {
          tj = (n + j - k % n) % n;
        }
        if (mat[i][j] != mat[i][tj]) { return false; }
      }
    }
    return true;
  }
};
