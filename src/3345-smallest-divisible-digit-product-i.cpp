// 3345. Smallest Divisible Digit Product I
// https://leetcode.com/problems/smallest-divisible-digit-product-i/

class Solution {
 public:
  int smallestNumber(int n, int t) {
    while (true) {
      int m = n;
      long long p = 1L;
      while (m) {
        p *= (m % 10);
        m /= 10;
      }
      if (p % t == 0) { return n; }
      ++n;
    }
    return -1;
  }
};
