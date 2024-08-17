// 1937. Maximum Number of Points with Cost
// https://leetcode.com/problems/maximum-number-of-points-with-cost/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  long long maxPoints(vector<vector<int>>& points) {
    int R = points.size(), C = points[0].size();
    vector<long long> prev(C);
    for (int c = 0; c < C; ++c) { prev[c] = points[0][c]; }
    for (int r = 1; r < R; ++r) {
      for (int c = 1; c < C; ++c) { prev[c] = max(prev[c - 1] - 1, prev[c]); }
      for (int c = C - 2; c >= 0; --c) { prev[c] = max(prev[c + 1] - 1, prev[c]); }
      for (int c = 0; c < C; ++c) { prev[c] += points[r][c]; }
    }
    long long ans = prev[0];
    for (int c = 1; c < C; ++c) { ans = max(ans, prev[c]); }
    return ans;
  }
};
