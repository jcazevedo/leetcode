// 326. Power of Three
// https://leetcode.com/problems/power-of-three/

#include <cmath>

class Solution {
public:
  bool isPowerOfThree(int n) {
    if (n <= 0)
      return false;
    double logNum = log10(n);
    double log3 = log10(3);
    double power = logNum / log3;
    double powerFloor = floor(power);
    double decimalPart = power - powerFloor;
    return abs(decimalPart) <= 0.0000000001;
  }
};
