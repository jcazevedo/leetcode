// 3047. Find the Largest Area of Square Inside Two Rectangles
// https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
    int N = bottomLeft.size();
    long long ans = 0L;
    for (int i = 0; i < N; ++i) {
      int isx = bottomLeft[i][0];
      int iex = topRight[i][0];
      int isy = bottomLeft[i][1];
      int iey = topRight[i][1];
      for (int j = i + 1; j < N; ++j) {
        int jsx = bottomLeft[j][0];
        int jex = topRight[j][0];
        int jsy = bottomLeft[j][1];
        int jey = topRight[j][1];
        if (isx > jex || jsx > iex) { continue; }
        if (isy > jey || jsy > iey) { continue; }
        long long xx = min(iex, jex) - max(isx, jsx);
        long long yy = min(iey, jey) - max(isy, jsy);
        ans = max(ans, min(xx, yy) * min(xx, yy));
      }
    }
    return ans;
  }
};
