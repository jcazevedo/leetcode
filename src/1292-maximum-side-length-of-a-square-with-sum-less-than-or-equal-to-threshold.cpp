// 1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold
// https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxSideLength(vector<vector<int>>& mat, int threshold) {
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> ps(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        ps[i][j] = mat[i][j];
        if (i > 0) { ps[i][j] += ps[i - 1][j]; }
        if (j > 0) { ps[i][j] += ps[i][j - 1]; }
        if (i > 0 && j > 0) { ps[i][j] -= ps[i - 1][j - 1]; }
      }
    }
    int ans = 0;
    int lo = 1;
    int hi = min(m, n);
    while (lo <= hi) {
      int l = lo + (hi - lo) / 2;
      bool good = false;
      for (int i = 0; i + l <= m; ++i) {
        for (int j = 0; j + l <= n; ++j) {
          int sum = ps[i + l - 1][j + l - 1];
          if (i > 0) { sum -= ps[i - 1][j + l - 1]; }
          if (j > 0) { sum -= ps[i + l - 1][j - 1]; }
          if (i > 0 && j > 0) { sum += ps[i - 1][j - 1]; }
          if (sum <= threshold) { good = true; }
        }
      }
      if (good) {
        ans = l;
        lo = l + 1;
      } else {
        hi = l - 1;
      }
    }
    return ans;
  }
};
