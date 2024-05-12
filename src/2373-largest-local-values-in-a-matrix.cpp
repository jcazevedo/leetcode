// 2373. Largest Local Values in a Matrix
// https://leetcode.com/problems/largest-local-values-in-a-matrix/

#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
    int N = grid.size();
    vector<vector<int>> ans = vector<vector<int>>(N - 2, vector<int>(N - 2, 0));
    for (int i = 1; i <= N - 2; ++i)
      for (int j = 1; j <= N - 2; ++j) {
        priority_queue<int> pq;
        for (int di = -1; di <= 1; ++di)
          for (int dj = -1; dj <= 1; ++dj) pq.push(grid[i + di][j + dj]);
        ans[i - 1][j - 1] = pq.top();
      }
    return ans;
  }
};
