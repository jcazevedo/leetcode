// 1329. Sort the Matrix Diagonally
// https://leetcode.com/problems/sort-the-matrix-diagonally/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    for (int i = 0; i < n; ++i) {
      vector<int> diag;
      int j = 0, k = i;
      while (j < m && k < n) diag.push_back(mat[j++][k++]);
      sort(diag.begin(), diag.end());
      j = 0;
      k = i;
      int d = 0;
      while (j < m && k < n) mat[j++][k++] = diag[d++];
    }
    for (int i = 1; i < m; ++i) {
      vector<int> diag;
      int j = i, k = 0;
      while (j < m && k < n) {
        diag.push_back(mat[j][k]);
        ++j;
        ++k;
      }
      sort(diag.begin(), diag.end());
      j = i, k = 0;
      int d = 0;
      while (j < m && k < n) mat[j++][k++] = diag[d++];
    }
    return mat;
  }
};
