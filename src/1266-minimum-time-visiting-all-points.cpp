// 1266. Minimum Time Visiting All Points
// https://leetcode.com/problems/minimum-time-visiting-all-points/

#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
 public:
  int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    int N = points.size(), ans = 0;
    for (int i = 1; i < N; ++i) {
      int dx = abs(points[i][0] - points[i - 1][0]);
      int dy = abs(points[i][1] - points[i - 1][1]);
      ans += max(dx, dy);
    }
    return ans;
  }
};
