// 2843. Count Symmetric Integers
// https://leetcode.com/problems/count-symmetric-integers/

class Solution {
 private:
  int len(int num) {
    int ans = 0;
    while (num) {
      ++ans;
      num /= 10;
    }
    return ans;
  }

  bool is_symmetric(int num) {
    int l = len(num);
    if (l % 2) { return false; }
    l /= 2;
    int left = 0, right = 0;
    while (num) {
      if (l) {
        right += num % 10;
        --l;
      } else {
        left += num % 10;
      }
      num /= 10;
    }
    return left == right;
  }

 public:
  int countSymmetricIntegers(int low, int high) {
    int ans = 0;
    for (int i = low; i <= high; ++i) { ans += is_symmetric(i); }
    return ans;
  }
};
