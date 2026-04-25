// 1611. Minimum One Bit Operations to Make Integers Zero
// https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/

class Solution {
 public:
  int minimumOneBitOperations(int n) {
    int res = 0;
    while (n > 0) {
      int k = 0;
      while ((1 << (k + 1)) <= n) { ++k; }
      res += (1 << k);
      n ^= (1 << k);
      if (k > 0) { n ^= (1 << (k - 1)); }
    }
    return res;
  }
};
