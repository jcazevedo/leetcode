// 1317. Convert Integer to the Sum of Two No-Zero Integers
// https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/

#include <vector>

using namespace std;

class Solution {
 private:
  bool isNoZero(int n) {
    while (n) {
      int dig = n % 10;
      if (dig == 0) { return false; }
      n /= 10;
    }
    return true;
  }

 public:
  vector<int> getNoZeroIntegers(int n) {
    for (int i = 1; i < n; ++i) {
      if (isNoZero(i) && isNoZero(n - i)) { return {i, n - i}; }
    }
    return {};
  }
};
