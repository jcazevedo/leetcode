// 1975. Maximum Matrix Sum
// https://leetcode.com/problems/maximum-matrix-sum/

#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>

using namespace std;

class Solution {
 public:
  long long maxMatrixSum(vector<vector<int>>& matrix) {
    int N = matrix.size(), cnt = 0, mn = numeric_limits<int>::max();
    long long ans = 0L;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        ans += abs(matrix[i][j]);
        mn = min(mn, abs(matrix[i][j]));
        if (matrix[i][j] < 0) { ++cnt; }
      }
    }
    if (cnt % 2) { ans -= mn * 2; }
    return ans;
  }
};
