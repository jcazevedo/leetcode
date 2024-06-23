// 2373. Largest Local Values in a Matrix
// https://leetcode.com/problems/largest-local-values-in-a-matrix/

#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
    int N = grid.size();
    vector<vector<int>> ans = vector<vector<int>>(N - 2, vector<int>(N - 2, 0));
    for (int i = 1; i <= N - 2; ++i)
      for (int j = 1; j <= N - 2; ++j)
        for (int di = -1; di <= 1; ++di)
          for (int dj = -1; dj <= 1; ++dj) ans[i - 1][j - 1] = max(ans[i - 1][j - 1], grid[i + di][j + dj]);
    return ans;
  }
};
