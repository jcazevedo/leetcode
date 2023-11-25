// 8. String to Integer (atoi)
// https://leetcode.com/problems/string-to-integer-atoi/

#include <string>

using namespace std;

class Solution {
 public:
  int myAtoi(string str) {
    int N = str.size();
    long long res = 0;
    bool neg = false, signal = false, inNumber = false;
    for (int i = 0; i < N; i++) {
      if (str[i] != ' ') {
        if (str[i] == '+' && !signal && !inNumber) {
          signal = true;
          inNumber = true;
        } else if (str[i] == '-' && !signal && !inNumber) {
          signal = true;
          neg = true;
          inNumber = true;
        } else if (isdigit(str[i])) {
          res = res * 10 + (str[i] - '0');
          if (neg && -res < INT32_MIN)
            return INT32_MIN;
          else if (!neg && res > INT32_MAX)
            return INT32_MAX;
          inNumber = true;
        } else {
          break;
        }
      } else if (inNumber) {
        break;
      }
    }
    return neg ? -res : res;
  }
};
