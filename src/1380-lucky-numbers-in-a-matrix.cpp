// 1380. Lucky Numbers in a Matrix
// https://leetcode.com/problems/lucky-numbers-in-a-matrix/

#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> luckyNumbers(vector<vector<int>>& matrix) {
    int R = matrix.size();
    int C = matrix[0].size();
    vector<int> minRow(R, numeric_limits<int>::max());
    vector<int> maxCol(C, numeric_limits<int>::min());
    for (int r = 0; r < R; ++r) {
      for (int c = 0; c < C; ++c) {
        minRow[r] = min(minRow[r], matrix[r][c]);
        maxCol[c] = max(maxCol[c], matrix[r][c]);
      }
    }
    vector<int> ans;
    for (int r = 0; r < R; ++r) {
      for (int c = 0; c < C; ++c) {
        if (matrix[r][c] == minRow[r] && matrix[r][c] == maxCol[c]) { ans.push_back(matrix[r][c]); }
      }
    }
    return ans;
  }
};
