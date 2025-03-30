// 2033. Minimum Operations to Make a Uni-Value Grid
// https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/

#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
 public:
  int minOperations(vector<vector<int>>& grid, int x) {
    int m = grid.size(), n = grid[0].size();
    vector<int> nums;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) { nums.push_back(grid[i][j]); }
    }
    sort(nums.begin(), nums.end());
    int target = nums[(m * n) / 2];
    int ans = 0;
    for (int i = 0; i < m * n; ++i) {
      if (nums[i] % x != target % x) { return -1; }
      ans += abs(target - nums[i]) / x;
    }
    return ans;
  }
};
