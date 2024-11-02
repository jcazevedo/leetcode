// 120. Triangle
// https://leetcode.com/problems/triangle/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumTotal(vector<vector<int>>& triangle) {
    int R = triangle.size();
    if (R == 1) { return triangle[0][0]; }
    int ans = 1e9;
    for (int r = 1; r < R; ++r) {
      for (int c = 0; c < (int)triangle[r].size(); c++) {
        int curr = triangle[r][c];
        triangle[r][c] = 1e9;
        if (c < (int)triangle[r - 1].size()) { triangle[r][c] = min(triangle[r][c], triangle[r - 1][c] + curr); }
        if (c > 0) { triangle[r][c] = min(triangle[r][c], triangle[r - 1][c - 1] + curr); }
        if (r == R - 1) { ans = min(ans, triangle[r][c]); }
      }
    }
    return ans;
  }
};
