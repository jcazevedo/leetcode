// 166. Fraction to Recurring Decimal
// https://leetcode.com/problems/fraction-to-recurring-decimal/

#include <cmath>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) { return "0"; }
    ostringstream ss;
    if ((numerator < 0) ^ (denominator < 0)) { ss << "-"; }
    long long num = abs((long long)numerator);
    long long den = abs((long long)denominator);
    ss << num / den;
    num %= den;
    if (num == 0) { return ss.str(); }
    ss << ".";
    int l = ss.str().size(), s = -1;
    unordered_map<long long, int> prev;
    prev[num] = l;
    while (num != 0) {
      num *= 10;
      ss << num / den;
      num %= den;
      ++l;
      if (prev.count(num)) {
        s = prev[num];
        break;
      } else {
        prev[num] = l;
      }
    }
    string ans = ss.str();
    if (s != -1) {
      ans.insert(s, "(");
      ans += ")";
    }
    return ans;
  }
};
