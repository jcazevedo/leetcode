// 1267. Count Servers that Communicate
// https://leetcode.com/problems/count-servers-that-communicate/

#include <vector>

using namespace std;

class Solution {
 public:
  int countServers(vector<vector<int>>& grid) {
    int H = grid.size();
    int W = grid[0].size();
    vector<int> columnCount(W, 0);
    vector<int> singleRowCount(W, 0);
    int ans = 0;
    for (int i = 0; i < H; ++i) {
      int rowCount = 0;
      int lastColumn = -1;
      for (int j = 0; j < W; ++j) {
        if (grid[i][j]) {
          ++rowCount;
          ++columnCount[j];
          lastColumn = j;
        }
      }
      if (rowCount > 1) {
        ans += rowCount;
      } else if (rowCount == 1) {
        ++singleRowCount[lastColumn];
      }
    }
    for (int j = 0; j < W; ++j) {
      if (columnCount[j] > 1) { ans += singleRowCount[j]; }
    }
    return ans;
  }
};
