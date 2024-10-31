// 2463. Minimum Total Distance Traveled
// https://leetcode.com/problems/minimum-total-distance-traveled/

#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define UNSET (-1L)
#define INF (1e18L)

class Solution {
 private:
  long long minimumDistance(
      int r, int f, const vector<int>& robot, const vector<int>& factory, vector<vector<long long>>& cache) {
    if (r >= (int)robot.size()) { return 0L; }
    if (f >= (int)factory.size()) { return INF; }
    if (cache[r][f] != UNSET) { return cache[r][f]; }
    long long best = min(abs(robot[r] - factory[f]) + minimumDistance(r + 1, f + 1, robot, factory, cache),
                         minimumDistance(r, f + 1, robot, factory, cache));
    cache[r][f] = best;
    return best;
  }

 public:
  long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
    sort(begin(robot), end(robot));
    sort(begin(factory), end(factory));
    vector<int> factoryPositions;
    for (const vector<int>& f : factory) {
      for (int i = 0; i < f[1]; ++i) { factoryPositions.push_back(f[0]); }
    }
    vector<vector<long long>> cache(robot.size(), vector<long long>(factoryPositions.size(), UNSET));
    return minimumDistance(0, 0, robot, factoryPositions, cache);
  }
};
