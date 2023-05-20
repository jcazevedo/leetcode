// 7. Reverse Integer
// https://leetcode.com/problems/reverse-integer/

#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
  int reverse(int x) {
    long long n = abs((double)x);
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
