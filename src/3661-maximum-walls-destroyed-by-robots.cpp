// 3661. Maximum Walls Destroyed by Robots
// https://leetcode.com/problems/maximum-walls-destroyed-by-robots/

#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
    int n = robots.size();
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int a, int b) { return robots[a] < robots[b]; });
    vector<int> pos(n), dist(n);
    for (int i = 0; i < n; ++i) {
      pos[i] = robots[idx[i]];
      dist[i] = distance[idx[i]];
    }
    sort(walls.begin(), walls.end());
    function<int(int, int)> countWalls = [&](int lo, int hi) -> int {
      if (lo > hi) { return 0; }
      return (int)(upper_bound(walls.begin(), walls.end(), hi) - lower_bound(walls.begin(), walls.end(), lo));
    };
    function<int(int)> wallAt = [&](int p) -> int { return binary_search(walls.begin(), walls.end(), p) ? 1 : 0; };
    function<int(int, int, int)> gapWalls = [&](int i, int prev, int cur) -> int {
      int gapLo = pos[i - 1] + 1, gapHi = pos[i] - 1;
      if (gapLo > gapHi) { return 0; }
      int rLo = gapLo, rHi = min(pos[i - 1] + dist[i - 1], gapHi);
      int lLo = max(pos[i] - dist[i], gapLo), lHi = gapHi;
      if (prev && cur) {
        return countWalls(rLo, rHi);
      } else if (!prev && !cur) {
        return countWalls(lLo, lHi);
      } else if (!prev && cur) {
        return 0;
      } else {
        int rc = countWalls(rLo, rHi);
        int lc = countWalls(lLo, lHi);
        int oLo = max(rLo, lLo), oHi = min(rHi, lHi);
        int oc = countWalls(oLo, oHi);
        return rc + lc - oc;
      }
    };
    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[0][0] = wallAt(pos[0]) + countWalls(pos[0] - dist[0], pos[0] - 1);
    dp[0][1] = wallAt(pos[0]);
    for (int i = 1; i < n; ++i) {
      int w = wallAt(pos[i]);
      for (int cur = 0; cur < 2; ++cur) {
        for (int prev = 0; prev < 2; ++prev) {
          dp[i][cur] = max(dp[i][cur], dp[i - 1][prev] + w + gapWalls(i, prev, cur));
        }
      }
    }
    return max(dp[n - 1][0], dp[n - 1][1] + countWalls(pos[n - 1] + 1, pos[n - 1] + dist[n - 1]));
  }
};
