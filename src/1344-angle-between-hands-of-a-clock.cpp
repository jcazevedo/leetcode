// 1344. Angle Between Hands of a Clock
// https://leetcode.com/problems/angle-between-hands-of-a-clock/

#include <cmath>

using namespace std;

class Solution {
 public:
  double angleClock(int hour, int minutes) {
    double hour_angle = 0.5 * (60 * hour + minutes);
    double minute_angle = 6 * minutes;
    double res = abs(minute_angle - hour_angle);
    if (res > 180) res = 360 - res;
    return res;
  }
};
