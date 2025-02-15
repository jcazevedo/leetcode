// 2698. Find the Punishment Number of an Integer
// https://leetcode.com/problems/find-the-punishment-number-of-an-integer/

class Solution {
 private:
  bool good(int curr, int sum) {
    if (curr == sum) { return true; }
    if (curr == 0) { return false; }
    int nDigits = 0;
    int tmp = curr;
    while (tmp) {
      ++nDigits;
      tmp /= 10;
    }
    int p = 10;
    for (int i = 1; i < nDigits; ++i) {
      int nextSum = sum - curr % p;
      if (nextSum < 0) { break; }
      if (good(curr / p, sum - curr % p)) { return true; }
      p *= 10;
    }
    return false;
  }

 public:
  int punishmentNumber(int n) {
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      int p = i * i;
      if (good(p, i)) { ans += p; }
    }
    return ans;
  }
};
