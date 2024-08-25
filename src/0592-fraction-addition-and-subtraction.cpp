// 592. Fraction Addition and Subtraction
// https://leetcode.com/problems/fraction-addition-and-subtraction/

#include <cmath>
#include <string>

using namespace std;

class Solution {
 private:
  int gcd(int a, int b) { return a == 0 ? b : gcd(b % a, a); }

 public:
  string fractionAddition(string expression) {
    int n = 0;
    int d = 1;
    int N = expression.size();
    int i = 0;
    while (i < N) {
      int cn = 0;
      int cd = 0;
      bool neg = false;
      if (expression[i] == '-') {
        neg = true;
        ++i;
      }
      if (expression[i] == '+') { ++i; }
      while (isdigit(expression[i])) {
        cn = cn * 10 + (expression[i] - '0');
        ++i;
      }
      if (neg) { cn *= -1; }
      ++i;
      while (i < N && isdigit(expression[i])) {
        cd = cd * 10 + (expression[i] - '0');
        ++i;
      }
      n = n * cd + cn * d;
      d = d * cd;
    }
    int gcdv = gcd(abs(n), abs(d));
    n = n / gcdv;
    d = d / gcdv;
    return (n < 0 ? "-" : "") + to_string(abs(n)) + "/" + to_string(abs(d));
  }
};
