// 1861. Rotating the Box
// https://leetcode.com/problems/rotating-the-box/

#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
    int M = box.size();
    int N = box[0].size();
    vector<vector<char>> ans(N, vector<char>(M, '.'));
    for (int m = 0; m < M; ++m) {
      int prevBlock = N;
      int cnt = 0;
      for (int n = N - 1; n >= -1; --n) {
        if (n == -1 || box[m][n] == '*') {
          int i = prevBlock;
          while (cnt--) { ans[--i][M - m - 1] = '#'; }
          prevBlock = n;
          cnt = 0;
          if (n != -1) { ans[n][M - m - 1] = '*'; }
        } else if (box[m][n] == '#') {
          ++cnt;
        }
      }
    }
    return ans;
  }
};
