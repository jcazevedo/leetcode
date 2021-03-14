#include <vector>

using namespace std;

class Solution {
public:
  int findMinArrowShots(vector<vector<int>>& points) {
    if (points.size() == 0)
      return 0;
    if (points.size() == 1)
      return 1;
    sort(points.begin(), points.end(),
         [](const vector<int>& v1, const vector<int>& v2) {
           return v1[1] < v2[1];
         });
    int ans = 1, prev = points[0][1];
    for (size_t i = 1; i < points.size(); ++i) {
      if (points[i][0] > prev) {
        ans++;
        prev = points[i][1];
      }
    }
    return ans;
  }
};
