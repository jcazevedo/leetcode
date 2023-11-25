// 69. Sqrt(x)
// https://leetcode.com/problems/sqrtx/

#include <limits>

using namespace std;

class Solution {
 public:
  int mySqrt(int x) {
    long long lo = 0, hi = x;
    while (lo < hi) {
      long long mid = lo + (hi - lo + 1) / 2;
      if (mid * mid <= x) {
        lo = mid;
      } else {
        hi = mid - 1;
      }
    }
    return lo;
  }
};
