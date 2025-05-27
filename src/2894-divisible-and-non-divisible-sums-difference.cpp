// 2894. Divisible and Non-divisible Sums Difference
// https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/

class Solution {
 public:
  int differenceOfSums(int n, int m) {
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      if (i % m) {
        ans += i;
      } else {
        ans -= i;
      }
    }
    return ans;
  }
};
