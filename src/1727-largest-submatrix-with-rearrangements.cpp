// 1727. Largest Submatrix With Rearrangements
// https://leetcode.com/problems/largest-submatrix-with-rearrangements/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int largestSubmatrix(vector<vector<int>>& matrix) {
    int M = matrix.size();
    int N = matrix[0].size();
    int ans = 0;
    for (int r = 0; r < M; ++r) {
      for (int c = 0; c < N; ++c) {
        if (matrix[r][c] != 0 && r > 0) { matrix[r][c] += matrix[r - 1][c]; }
      }
      vector<int> row = matrix[r];
      sort(row.begin(), row.end(), greater<int>());
      for (int i = 0; i < N; ++i) { ans = max(ans, row[i] * (i + 1)); }
    }
    return ans;
  }
};
