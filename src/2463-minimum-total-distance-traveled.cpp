// 2463. Minimum Total Distance Traveled
// https://leetcode.com/problems/minimum-total-distance-traveled/

#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define INF 1000000000000000000LL

class Solution {
 public:
  long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
    sort(begin(robot), end(robot));
    sort(begin(factory), end(factory));
    vector<int> fp;
    for (const vector<int>& f : factory) {
      for (int i = 0; i < f[1]; ++i) { fp.push_back(f[0]); }
    }
    int R = robot.size(), F = fp.size();
    vector<vector<long long>> dp(R + 1, vector<long long>(F + 1, INF));
    for (int f = 0; f <= F; ++f) { dp[R][f] = 0; }
    for (int r = R - 1; r >= 0; --r) {
      for (int f = F - 1; f >= 0; --f) { dp[r][f] = min(abs(robot[r] - fp[f]) + dp[r + 1][f + 1], dp[r][f + 1]); }
    }
    return dp[0][0];
  }
};
