// 2749. Minimum Operations to Make the Integer Zero
// https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/

class Solution {
 public:
  int makeTheIntegerZero(int num1, int num2) {
    int ans = 1;
    while (true) {
      long long curr = num1 - ((long long)num2) * ans;
      if (curr < ans) { return -1; }
      if (ans >= __builtin_popcountll(curr)) { return ans; }
      ++ans;
    }
    return ans;
  }
};
