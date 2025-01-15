// 2429. Minimize XOR
// https://leetcode.com/problems/minimize-xor/

class Solution {
 public:
  int minimizeXor(int num1, int num2) {
    int cnt = 0;
    for (int i = 0; i <= 30; ++i) {
      if ((1 << i) & num2) { ++cnt; }
    }
    int ans = 0;
    for (int i = 30; i >= 0 && cnt > 0; --i) {
      if (num1 & (1 << i)) {
        ans |= (1 << i);
        --cnt;
      }
    }
    for (int i = 0; i <= 30 && cnt > 0; ++i) {
      if (!(ans & (1 << i))) {
        ans |= (1 << i);
        --cnt;
      }
    }
    return ans;
  }
};
