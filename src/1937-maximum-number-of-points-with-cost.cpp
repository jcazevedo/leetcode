// 1937. Maximum Number of Points with Cost
// https://leetcode.com/problems/maximum-number-of-points-with-cost/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  long long maxPoints(vector<vector<int>>& points) {
    int R = points.size(), C = points[0].size();
    vector<long long> prev(C), left(C), right(C);
    for (int c = 0; c < C; ++c) { prev[c] = points[0][c]; }
    for (int r = 1; r < R; ++r) {
      left[0] = prev[0];
      for (int c = 1; c < C; ++c) { left[c] = max(left[c - 1] - 1, prev[c]); }
      right[C - 1] = prev[C - 1];
      for (int c = C - 2; c >= 0; --c) { right[c] = max(right[c + 1] - 1, prev[c]); }
      for (int c = 0; c < C; ++c) { prev[c] = max(left[c], right[c]) + points[r][c]; }
    }
    long long ans = prev[0];
    for (int c = 1; c < C; ++c) { ans = max(ans, prev[c]); }
    return ans;
  }
};
