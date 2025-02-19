// 149. Max Points on a Line
// https://leetcode.com/problems/max-points-on-a-line/

#include <algorithm>
#include <map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxPoints(vector<vector<int>> &points) {
    int n = points.size();
    if (n == 1) { return 1; }
    map<int, unordered_set<int>> v;
    map<pair<double, double>, unordered_set<int>> l;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        int x1 = points[i][0];
        int y1 = points[i][1];
        int x2 = points[j][0];
        int y2 = points[j][1];
        if (x1 == x2) {
          v[x1].insert(i);
          v[x1].insert(j);
        } else {
          double m = ((double)(y1 - y2)) / (x1 - x2);
          double b = ((double)(x1 * y2 - x2 * y1)) / (x1 - x2);
          l[{m, b}].insert(i);
          l[{m, b}].insert(j);
        }
      }
    }
    int ans = 0;
    for (auto &[_, s] : v) { ans = max(ans, (int)s.size()); }
    for (auto &[_, s] : l) { ans = max(ans, (int)s.size()); }
    return ans;
  }
};
