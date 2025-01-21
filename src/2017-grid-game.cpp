// 2017. Grid Game
// https://leetcode.com/problems/grid-game/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  long long gridGame(vector<vector<int>>& grid) {
    int N = grid[0].size();
    vector<vector<long long>> prefixSum(2, vector<long long>(N, 0L));
    for (int i = 0; i < 2; ++i) {
      prefixSum[i][0] = grid[i][0];
      for (int j = 1; j < N; ++j) { prefixSum[i][j] = prefixSum[i][j - 1] + grid[i][j]; }
    }
    long long ans = numeric_limits<long long>::max();
    for (int i = 0; i < N; ++i) {
      long long best = prefixSum[0][N - 1] - prefixSum[0][i];
      if (i > 0) { best = max(best, prefixSum[1][i - 1]); }
      ans = min(ans, best);
    }
    return ans;
  }
};
