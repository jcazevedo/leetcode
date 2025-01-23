// 1267. Count Servers that Communicate
// https://leetcode.com/problems/count-servers-that-communicate/

#include <vector>

using namespace std;

class Solution {
 public:
  int countServers(vector<vector<int>>& grid) {
    int H = grid.size(), W = grid[0].size();
    vector<int> r(H, 0), c(W, 0);
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        if (grid[i][j]) {
          ++r[i];
          ++c[j];
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        if (grid[i][j] && (r[i] > 1 || c[j] > 1)) { ++ans; }
      }
    }
    return ans;
  }
};
