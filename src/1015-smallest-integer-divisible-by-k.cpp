// 1015. Smallest Integer Divisible by K
// https://leetcode.com/problems/smallest-integer-divisible-by-k/

class Solution {
public:
  int smallestRepunitDivByK(int K) {
    if (K % 2 == 0 || K % 5 == 0)
      return -1;
    int rem = 0;
    for (int i = 1; i <= K; ++i) {
      rem = (10 * rem + 1) % K;
      if (rem == 0)
        return i;
    }
    return -1;
  }
};
