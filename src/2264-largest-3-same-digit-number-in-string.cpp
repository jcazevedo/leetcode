// 2264. Largest 3-Same-Digit Number in String
// https://leetcode.com/problems/largest-3-same-digit-number-in-string/

#include <string>

using namespace std;

class Solution {
 public:
  string largestGoodInteger(string num) {
    int N = num.size(), cnt = 1;
    char largest = ' ';
    for (int i = 1; i < N; ++i) {
      if (num[i] == num[i - 1]) {
        cnt++;
      } else {
        cnt = 1;
      }
      if (cnt == 3 && (largest == ' ' || num[i] > largest)) {
        largest = num[i];
      }
    }
    if (largest == ' ') { return ""; }
    return string(3, largest);
  }
};
