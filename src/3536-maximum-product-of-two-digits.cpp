// 3536. Maximum Product of Two Digits
// https://leetcode.com/problems/maximum-product-of-two-digits/

#include <vector>

using namespace std;

class Solution {
 public:
  int maxProduct(int n) {
    vector<int> digits(10, 0);
    while (n) {
      int d = n % 10;
      ++digits[d];
      n /= 10;
    }
    int ans = 1, used = 0;
    for (int d = 9; d >= 0 && used < 2; --d) {
      if (digits[d] == 0) { continue; }
      ans *= d;
      ++used;
      if (digits[d] > 1 && used < 2) {
        ans *= d;
        ++used;
      }
    }
    return ans;
  }
};
