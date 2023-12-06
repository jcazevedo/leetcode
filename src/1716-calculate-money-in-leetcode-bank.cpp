// 1716. Calculate Money in Leetcode Bank
// https://leetcode.com/problems/calculate-money-in-leetcode-bank/

class Solution {
 public:
  int totalMoney(int n) {
    int ans = 1, mon = 1, prev = 1;
    for (int i = 1; i < n; ++i) {
      if (i % 7 == 0) {
        ++mon;
        ans += mon;
        prev = mon;
      } else {
        prev++;
        ans += prev;
      }
    }
    return ans;
  }
};
