// 650. 2 Keys Keyboard
// https://leetcode.com/problems/2-keys-keyboard/

class Solution {
 public:
  int minSteps(int n) {
    int ans = 0;
    int d = 2;
    while (n > 1) {
      while (n % d == 0) {
        ans += d;
        n /= d;
      }
      ++d;
    }
    return ans;
  }
};
