// 1937. Maximum Number of Points with Cost
// https://leetcode.com/problems/maximum-number-of-points-with-cost/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  long long maxPoints(vector<vector<int>>& points) {
    int M = points.size(), N = points[0].size();
    vector<long long> prev(N);
    for (int c = 0; c < N; ++c) { prev[c] = points[0][c]; }
    for (int r = 1; r < M; ++r) {
      for (int c = 1; c < N; ++c) { prev[c] = max(prev[c - 1] - 1, prev[c]); }
      for (int c = N - 2; c >= 0; --c) { prev[c] = max(prev[c + 1] - 1, prev[c]); }
      for (int c = 0; c < N; ++c) { prev[c] += points[r][c]; }
    }
    long long ans = prev[0];
    for (int c = 1; c < N; ++c) { ans = max(ans, prev[c]); }
    return ans;
  }
};
