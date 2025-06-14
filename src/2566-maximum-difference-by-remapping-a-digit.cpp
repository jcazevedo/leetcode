// 2566. Maximum Difference by Remapping a Digit
// https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/

class Solution {
 private:
  int remap(int num, int from, int to) {
    int ans = 0;
    int p = 1;
    while (num) {
      int d = num % 10;
      ans += (d == from ? to : d) * p;
      num /= 10;
      p *= 10;
    }
    return ans;
  }

 public:
  int minMaxDifference(int num) {
    int min_v = -1, max_v = -1;
    for (int from = 0; from <= 9; ++from) {
      for (int to = 0; to <= 9; ++to) {
        if (from == to) { continue; }
        int remapped = remap(num, from, to);
        if (min_v == -1 || remapped < min_v) { min_v = remapped; }
        if (max_v == -1 || remapped > max_v) { max_v = remapped; }
      }
    }
    return max_v - min_v;
  }
};
