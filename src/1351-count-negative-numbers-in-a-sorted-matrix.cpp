// 1351. Count Negative Numbers in a Sorted Matrix
// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

#include <vector>

using namespace std;

class Solution {
public:
  int countNegatives(vector<vector<int>>& grid) {
    int M = grid.size();
    if (M == 0)
      return 0;
    int N = grid[0].size();
    if (N == 0)
      return 0;
    int ans = 0;
    int j = N;
    for (int i = 0; i < M; ++i) {
      while (j > 0 && grid[i][j - 1] < 0)
        --j;
      ans += N - j;
    }
    return ans;
  }
};
