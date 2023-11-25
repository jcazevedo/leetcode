// 7. Reverse Integer
// https://leetcode.com/problems/reverse-integer/

#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
  int reverse(int x) {
    int ans = 0, maxValue = numeric_limits<int>::max(),
        minValue = numeric_limits<int>::min();
    while (x != 0) {
      int digit = x % 10;
      x /= 10;
      if (ans > maxValue / 10 || (ans == maxValue / 10 && digit > 7))
        return 0;
      if (ans < minValue / 10 || (ans == minValue / 10 && digit < -8))
        return 0;
      ans = ans * 10 + digit;
    }
    return ans;
  }
};
