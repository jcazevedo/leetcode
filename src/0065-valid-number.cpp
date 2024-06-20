// 65. Valid Number
// https://leetcode.com/problems/valid-number/

#include <string>

using namespace std;

enum State { INIT, I1, I2, I3, I4, I5, F1, F2, F3 };

class Solution {
 private:
  bool isFinalState(State s) { return s == F1 || s == F2 || s == F3; }

 public:
  bool isNumber(string s) {
    State state = INIT;
    for (const char& ch : s) {
      if (state == INIT) {
        if (ch == '+' || ch == '-')
          state = I1;
        else if (ch >= '0' && ch <= '9')
          state = F1;
        else if (ch == '.')
          state = I2;
        else
          return false;
      } else if (state == I1) {
        if (ch >= '0' && ch <= '9')
          state = F1;
        else if (ch == '.')
          state = I2;
        else
          return false;
      } else if (state == F1) {
        if (ch == 'e' || ch == 'E')
          state = I3;
        else if (ch == '.')
          state = F2;
        else if (ch >= '0' && ch <= '9')
          state = F1;
        else
          return false;
      } else if (state == I2) {
        if (ch >= '0' && ch <= '9')
          state = F2;
        else
          return false;
      } else if (state == I3) {
        if (ch >= '0' && ch <= '9')
          state = F3;
        else if (ch == '+' || ch == '-')
          state = I5;
        else
          return false;
      } else if (state == F2) {
        if (ch == 'e' || ch == 'E')
          state = I4;
        else if (ch >= '0' && ch <= '9')
          state = F2;
        else
          return false;
      } else if (state == I4) {
        if (ch >= '0' && ch <= '9')
          state = F3;
        else if (ch == '+' || ch == '-')
          state = I5;
        else
          return false;
      } else if (state == I5) {
        if (ch >= '0' && ch <= '9')
          state = F3;
        else
          return false;
      } else if (state == F3) {
        if (ch >= '0' && ch <= '9')
          state = F3;
        else
          return false;
      }
    }
    return isFinalState(state);
  }
};
