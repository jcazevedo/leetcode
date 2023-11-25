// 1870. Minimum Speed to Arrive on Time
// https://leetcode.com/problems/minimum-speed-to-arrive-on-time/

#include <vector>

using namespace std;

class Solution {
 private:
  double getTime(const vector<int>& dist, int speed) {
    double ans = 0;
    for (unsigned int i = 0; i < dist.size(); ++i) {
      if (i + 1 < dist.size()) {
        ans += (dist[i] + speed - 1) / speed;
      } else {
        ans += (double)dist[i] / speed;
      }
    }
    return ans;
  }

 public:
  int minSpeedOnTime(vector<int>& dist, double hour) {
    int lo = 1, hi = 1e7;
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if (getTime(dist, mid) <= hour) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    if (getTime(dist, lo) <= hour) return lo;
    return -1;
  }
};
