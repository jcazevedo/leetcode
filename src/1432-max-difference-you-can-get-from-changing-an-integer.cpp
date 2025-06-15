// 1432. Max Difference You Can Get From Changing an Integer
// https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 private:
  vector<int> to_digits(int num) {
    vector<int> ans;
    while (num) {
      ans.push_back(num % 10);
      num /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }

 public:
  int maxDiff(int num) {
    vector<int> digits = to_digits(num);
    int n = digits.size(), i = 0, a = 0, b = 0;
    while (i < n && digits[i] == 9) { ++i; }
    if (i >= n) {
      for (int d : digits) { a = a * 10 + d; }
    } else {
      int rep = digits[i];
      for (int d : digits) {
        if (d == rep) {
          a = a * 10 + 9;
        } else {
          a = a * 10 + d;
        }
      }
    }
    if (digits[0] != 1) {
      int rep = digits[0];
      for (int d : digits) {
        if (d == rep) {
          b = b * 10 + 1;
        } else {
          b = b * 10 + d;
        }
      }
    } else {
      i = 1;
      while (i < n && (digits[i] == 0 || digits[i] == 1)) { ++i; }
      if (i >= n) {
        for (int d : digits) { b = b * 10 + d; }
      } else {
        int rep = digits[i];
        for (int d : digits) {
          if (d == rep) {
            b = b * 10;
          } else {
            b = b * 10 + d;
          }
        }
      }
    }
    return a - b;
  }
};
