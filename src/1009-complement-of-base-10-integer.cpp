// 1009. Complement of Base 10 Integer
// https://leetcode.com/problems/complement-of-base-10-integer/

class Solution {
 public:
  int bitwiseComplement(int N) {
    int res = 0, idx = 0;
    if (N == 0) return 1;
    while (N) {
      if (N % 2 == 0) res += (1 << idx);
      idx++;
      N /= 2;
    }
    return res;
  }
};
