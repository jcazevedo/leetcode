// 476. Number Complement
// https://leetcode.com/problems/number-complement/

class Solution {
 public:
  int findComplement(int num) {
    int res = 0, idx = 0;
    if (num == 0) return 1;
    while (num) {
      if (num % 2 == 0) res += (1 << idx);
      idx++;
      num /= 2;
    }
    return res;
  }
};
