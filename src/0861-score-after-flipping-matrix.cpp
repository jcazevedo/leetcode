// 861. Score After Flipping Matrix
// https://leetcode.com/problems/score-after-flipping-matrix/

#include <vector>

using namespace std;

class Solution {
 public:
  int matrixScore(vector<vector<int>>& grid) {
    int M = grid.size(), N = grid[0].size();

    for (int i = 0; i < M; ++i)
      if (grid[i][0] == 0)
        for (int j = 0; j < N; ++j) grid[i][j] = grid[i][j] ^ 1;

    for (int j = 0; j < N; ++j) {
      int bitSets = 0;
      for (int i = 0; i < M; ++i) bitSets += grid[i][j];
      if (bitSets <= M / 2)
        for (int i = 0; i < M; ++i) grid[i][j] = grid[i][j] ^ 1;
    }

    int ans = 0;
    for (int i = 0; i < M; ++i) {
      int curr = 0;
      for (int j = 0; j < N; ++j) curr = curr * 2 + grid[i][j];
      ans += curr;
    }

    return ans;
  }
};
