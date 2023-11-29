// 191. Number of 1 Bits
// https://leetcode.com/problems/number-of-1-bits/

#include <cstdint>

class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int ans = 0;
    for (int i = 0; i < 32; ++i) {
      if (n & (1 << i)) { ++ans; }
    }
    return ans;
  }
};
