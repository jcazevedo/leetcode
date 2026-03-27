// 2946. Matrix Similarity After Cyclic Shifts
// https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/

#include <vector>

using namespace std;

class Solution {
 public:
  bool areSimilar(vector<vector<int>>& mat, int k) {
    int m = mat.size(), n = mat[0].size();
    k %= n;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int tj = i % 2 == 0 ? (j + k) % n : (n + j - k) % n;
        if (mat[i][j] != mat[i][tj]) { return false; }
      }
    }
    return true;
  }
};
