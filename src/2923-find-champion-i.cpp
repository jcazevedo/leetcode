// 2923. Find Champion I
// https://leetcode.com/problems/find-champion-i/

#include <vector>

using namespace std;

class Solution {
 public:
  int findChampion(vector<vector<int>>& grid) {
    int N = grid.size();
    for (int i = 0; i < N; ++i) {
      int j = 0;
      for (; j < N; ++j) {
        if (i == j) continue;
        if (grid[i][j] != 1) break;
      }
      if (j == N) return i;
    }
    return -1;
  }
};
