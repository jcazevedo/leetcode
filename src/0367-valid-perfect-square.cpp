// 367. Valid Perfect Square
// https://leetcode.com/problems/valid-perfect-square/

class Solution {
public:
  bool isPerfectSquare(int num) {
    for (long long i = 1; i * i <= num; ++i) {
      if (num % i == 0 && num / i == i)
        return true;
    }
    return false;
  }
};
