// 885. Spiral Matrix III
// https://leetcode.com/problems/spiral-matrix-iii/

#include <vector>

using namespace std;

class Solution {
 private:
  const static vector<vector<int>> dirs;

 public:
  vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
    vector<vector<int>> ans;
    int r = rStart;
    int c = cStart;
    int t = 2;
    int l = 1;
    int maxL = 1;
    int d = 0;
    ans.push_back({r, c});
    while ((int)ans.size() != rows * cols) {
      r += dirs[d][0];
      c += dirs[d][1];
      if (r >= 0 && r < rows && c >= 0 && c < cols) { ans.push_back({r, c}); }
      --l;
      if (l == 0) {
        --t;
        if (t == 0) {
          t = 2;
          ++maxL;
        }
        l = maxL;
        d = (d + 1) % dirs.size();
      }
    }
    return ans;
  }
};

const vector<vector<int>> Solution::dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
