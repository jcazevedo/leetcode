// 29. Divide Two Integers
// https://leetcode.com/problems/divide-two-integers/

#include <cmath>
#include <limits>

using namespace std;

class Solution {
public:
  int divide(int dividend, int divisor) {
    if (divisor == 0 || (dividend == numeric_limits<int>::min() && divisor == -1))
      return numeric_limits<int>::max();
    long long absDividend = abs((long long)dividend);
    long long absDivisor = abs((long long)divisor);
    long long ans = 0;
    while (absDividend >= absDivisor) {
      int p = 0;
      while (absDividend >= (absDivisor << p))
        ++p;
      ans += 1 << (p - 1);
      absDividend -= absDivisor << (p - 1);
    }
    if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
      ans = -ans;
    return ans;
  }
};
