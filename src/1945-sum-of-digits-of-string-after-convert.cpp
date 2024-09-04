// 1945. Sum of Digits of String After Convert
// https://leetcode.com/problems/sum-of-digits-of-string-after-convert/

#include <string>

using namespace std;

class Solution {
 public:
  int getLucky(string s, int k) {
    int num = 0;
    for (const char& ch : s) {
      int d = (ch - 'a') + 1;
      while (d) {
        num += d % 10;
        d /= 10;
      }
    }
    int next;
    while (--k > 0) {
      next = 0;
      while (num) {
        next += num % 10;
        num /= 10;
      }
      num = next;
    }
    return num;
  }
};
