// 2594. Minimum Time to Repair Cars
// https://leetcode.com/problems/minimum-time-to-repair-cars/

#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>

using namespace std;

class Solution {
 private:
  bool good(long long time, const vector<int>& ranks, int cars) {
    long long tot = 0;
    for (int r : ranks) { tot += (long long)sqrt(time / r); }
    return tot >= cars;
  }

 public:
  long long repairCars(vector<int>& ranks, int cars) {
    long long lo = 0L, hi = 0L;
    for (int r : ranks) { hi = max(hi, ((long long)r) * cars * cars); }
    while (lo < hi) {
      long long mid = lo + (hi - lo) / 2;
      if (good(mid, ranks, cars)) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    return lo;
  }
};
