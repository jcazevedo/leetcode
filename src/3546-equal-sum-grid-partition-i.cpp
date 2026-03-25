// 3546. Equal Sum Grid Partition I
// https://leetcode.com/problems/equal-sum-grid-partition-i/

#include <vector>

using namespace std;

class Solution {
 public:
  bool canPartitionGrid(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    long long sum = 0L, acc;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) { sum += grid[i][j]; }
    }
    acc = 0L;
    for (int i = 0; i < m - 1; ++i) {
      for (int j = 0; j < n; ++j) { acc += grid[i][j]; }
      if (acc * 2L == sum) { return true; }
    }
    acc = 0L;
    for (int j = 0; j < n - 1; ++j) {
      for (int i = 0; i < m; ++i) { acc += grid[i][j]; }
      if (acc * 2L == sum) { return true; }
    }
    return false;
  }
};
