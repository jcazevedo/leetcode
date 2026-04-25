// 3464. Maximize the Distance Between Points on a Square
// https://leetcode.com/problems/maximize-the-distance-between-points-on-a-square/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxDistance(int side, vector<vector<int>>& points, int k) {
    int n = points.size();
    long long S = side;
    long long P = 4 * S;
    vector<long long> p(n);
    for (int i = 0; i < n; ++i) {
      long long x = points[i][0], y = points[i][1];
      if (y == 0) {
        p[i] = x;
      } else if (x == S) {
        p[i] = S + y;
      } else if (y == S) {
        p[i] = 2 * S + (S - x);
      } else {
        p[i] = 3 * S + (S - y);
      }
    }
    sort(p.begin(), p.end());
    int m = 2 * n;
    vector<long long> q(m);
    for (int i = 0; i < n; ++i) {
      q[i] = p[i];
      q[i + n] = p[i] + P;
    }
    int LOG = 1;
    while ((1 << LOG) < k) { ++LOG; }
    vector<vector<int>> up(LOG + 1, vector<int>(m, m));
    long long lo = 0, hi = P;
    while (lo < hi) {
      long long d = lo + (hi - lo + 1) / 2;
      int j = 0;
      for (int i = 0; i < m; ++i) {
        if (j < i + 1) { j = i + 1; }
        while (j < m && q[j] - q[i] < d) { ++j; }
        up[0][i] = j;
      }
      for (int b = 1; b <= LOG; ++b) {
        for (int i = 0; i < m; ++i) {
          int mid = up[b - 1][i];
          up[b][i] = (mid >= m) ? m : up[b - 1][mid];
        }
      }
      bool good = false;
      for (int i = 0; i < n && !good; ++i) {
        int cur = i;
        int steps = k - 1;
        for (int b = LOG; b >= 0 && cur < m; --b) {
          if ((steps >> b) & 1) { cur = up[b][cur]; }
        }
        if (cur < m && q[cur] - q[i] <= P - d) { good = true; }
      }
      if (good) {
        lo = d;
      } else {
        hi = d - 1;
      }
    }
    return lo;
  }
};
