// 3870. Count Commas in Range
// https://leetcode.com/problems/count-commas-in-range/

class Solution {
 public:
  int countCommas(int n) {
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      int num = i;
      while (num) {
        num /= 1000;
        if (num) { ++ans; }
      }
    }
    return ans;
  }
};
