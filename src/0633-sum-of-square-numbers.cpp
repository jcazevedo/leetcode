// 633. Sum of Square Numbers
// https://leetcode.com/problems/sum-of-square-numbers/

#include <cmath>

class Solution {
 public:
  bool judgeSquareSum(int c) {
    int a = 0;
    while (a * a <= c / 2) {
      int bSq = c - a * a;
      int b = sqrt(bSq);
      if (b * b == bSq) return true;
      ++a;
    }
    return false;
  }
};
