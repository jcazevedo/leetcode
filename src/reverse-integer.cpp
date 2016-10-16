#include <cmath>
#include <climits>

class Solution {
public:
  int reverse(int x) {
    long long n = abs((long long) x);
    long long res = 0;
    while (n) {
      res = res * 10 + n % 10;
      if (res > INT_MAX)
        return 0;
      n /= 10;
    }
    if (x < 0)
      return -res;
    return res;
  }
};
