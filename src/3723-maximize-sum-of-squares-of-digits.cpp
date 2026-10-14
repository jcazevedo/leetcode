// 3723. Maximize Sum of Squares of Digits
// https://leetcode.com/problems/maximize-sum-of-squares-of-digits/

#include <algorithm>
#include <string>

using namespace std;

class Solution {
 public:
  string maxSumOfSquares(int num, int sum) {
    string answer = "";
    for (int i = 0; i < num; ++i) {
      int digit = min(9, sum);
      sum -= digit;
      answer += digit + '0';
    }
    if (sum > 0) { return ""; }
    return answer;
  }
};
