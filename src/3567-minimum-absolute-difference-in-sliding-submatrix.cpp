// 3567. Minimum Absolute Difference in Sliding Submatrix
// https://leetcode.com/problems/minimum-absolute-difference-in-sliding-submatrix/

#include <algorithm>
#include <limits>
#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> ans = vector<vector<int>>(m - k + 1, vector<int>(n - k + 1, 0));
    for (int i = 0; i + k <= m; ++i) {
      for (int j = 0; j + k <= n; ++j) {
        set<int> values;
        for (int ii = i; ii < i + k; ++ii) {
          for (int jj = j; jj < j + k; ++jj) { values.insert(grid[ii][jj]); }
        }
        if (values.size() == 1) {
          ans[i][j] = 0;
        } else {
          ans[i][j] = numeric_limits<int>::max();
          for (set<int>::iterator itr = values.begin(); itr != values.end(); ++itr) {
            set<int>::iterator itr1 = itr;
            ++itr1;
            if (itr1 != values.end()) { ans[i][j] = min(ans[i][j], *itr1 - *itr); }
          }
        }
      }
    }
    return ans;
  }
};
