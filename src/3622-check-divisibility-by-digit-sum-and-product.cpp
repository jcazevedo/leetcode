// 3622. Check Divisibility by Digit Sum and Product
// https://leetcode.com/problems/check-divisibility-by-digit-sum-and-product/

class Solution {
 public:
  bool checkDivisibility(int n) {
    int sum = 0, mult = 1, tmp = n;
    while (tmp) {
      int d = tmp % 10;
      sum += d;
      mult *= d;
      tmp /= 10;
    }
    return n % (sum + mult) == 0;
  }
};
