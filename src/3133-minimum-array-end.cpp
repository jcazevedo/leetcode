// 3133. Minimum Array End
// https://leetcode.com/problems/minimum-array-end/

class Solution {
 public:
  long long minEnd(int n, int x) {
    long long rem = n - 1L, ans = 0L, andV = x;
    int b = 0;
    for (int i = 0; i < 63; ++i) {
      if (andV & (1L << i)) {
        ans |= (1L << i);
      } else {
        if (rem & (1L << b)) { ans |= (1L << i); }
        ++b;
      }
    }
    return ans;
  }
};
