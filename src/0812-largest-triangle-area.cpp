// 812. Largest Triangle Area
// https://leetcode.com/problems/largest-triangle-area/

#include <cmath>
#include <vector>

using namespace std;

class Solution {
 public:
  double largestTriangleArea(vector<vector<int>>& points) {
    double ans = 0.0;
    int P = points.size();
    for (int i = 0; i < P; ++i) {
      for (int j = i + 1; j < P; ++j) {
        double ij = sqrt((points[j][0] - points[i][0]) * (points[j][0] - points[i][0]) +
                         (points[j][1] - points[i][1]) * (points[j][1] - points[i][1]));
        for (int k = j + 1; k < P; ++k) {
          double jk = sqrt((points[k][0] - points[j][0]) * (points[k][0] - points[j][0]) +
                           (points[k][1] - points[j][1]) * (points[k][1] - points[j][1]));
          double ki = sqrt((points[i][0] - points[k][0]) * (points[i][0] - points[k][0]) +
                           (points[i][1] - points[k][1]) * (points[i][1] - points[k][1]));
          double s = (ij + jk + ki) / 2.0;
          double area = sqrt(s * (s - ij) * (s - jk) * (s - ki));
          ans = max(ans, area);
        }
      }
    }
    return ans;
  }
};
