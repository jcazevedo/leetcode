#include <cmath>

class Solution {
 public:
  int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    int T = minutesToTest / minutesToDie;
    int ans = 0;
    while (pow(T + 1, ans) < buckets) ++ans;
    return ans;
  }
};
