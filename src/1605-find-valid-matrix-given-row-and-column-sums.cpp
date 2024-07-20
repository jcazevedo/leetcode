// 1605. Find Valid Matrix Given Row and Column Sums
// https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
    int R = rowSum.size();
    int C = colSum.size();
    vector<vector<int>> ans(R, vector<int>(C, 0));
    vector<int> rowCurr(R, 0);
    vector<int> colCurr(C, 0);
    for (int r = 0; r < R; ++r) {
      for (int c = 0; c < C; ++c) {
        ans[r][c] = min(rowSum[r] - rowCurr[r], colSum[c] - colCurr[c]);
        rowCurr[r] += ans[r][c];
        colCurr[c] += ans[r][c];
      }
    }
    return ans;
  }
};
