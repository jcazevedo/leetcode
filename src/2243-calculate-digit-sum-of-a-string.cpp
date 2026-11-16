// 2243. Calculate Digit Sum of a String
// https://leetcode.com/problems/calculate-digit-sum-of-a-string/

#include <string>

using namespace std;

class Solution {
 public:
  string digitSum(string s, int k) {
    while ((int)s.size() > k) {
      string next;
      for (int i = 0; i < (int)s.size(); i += k) {
        int sum = 0;
        for (int j = i; j < (int)s.size() && j < i + k; ++j) { sum += s[j] - '0'; }
        next += to_string(sum);
      }
      s = next;
    }
    return s;
  }
};
