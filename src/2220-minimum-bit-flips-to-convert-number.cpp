// 2220. Minimum Bit Flips to Convert Number
// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/

class Solution {
 public:
  int minBitFlips(int start, int goal) { return __builtin_popcount(start ^ goal); }
};
