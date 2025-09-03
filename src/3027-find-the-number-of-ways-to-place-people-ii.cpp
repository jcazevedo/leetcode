// 3027. Find the Number of Ways to Place People II
// https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/

#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

class Solution {
 public:
  int numberOfPairs(vector<vector<int>>& points) {
    int ans = 0, n = points.size();
    sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
      if (a[0] < b[0]) { return true; }
      if (a[0] == b[0]) { return a[1] > b[1]; }
      return false;
    });
    for (int i = 0; i < n; ++i) {
      int min_y = numeric_limits<int>::min();
      for (int j = i + 1; j < n; ++j) {
        if (points[j][1] > points[i][1]) { continue; }
        if (points[j][1] <= min_y) { continue; }
        ++ans;
        min_y = max(points[j][1], min_y);
      }
    }
    return ans;
  }
};
