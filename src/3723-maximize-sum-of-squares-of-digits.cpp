// 3723. Maximize Sum of Squares of Digits
// https://leetcode.com/problems/maximize-sum-of-squares-of-digits/

#include <algorithm>
#include <string>

using namespace std;

class Solution {
 public:
  string maxSumOfSquares(int num, int sum) {
    int nines = sum / 9;
    int rem = sum % 9;
    if (nines + (rem != 0 ? 1 : 0) > num) { return ""; }
    string answer(nines, '9');
    if (rem != 0) { answer += string(1, rem + '0'); }
    answer += string(max(num - nines - (rem != 0 ? 1 : 0), 0), '0');
    return answer;
  }
};
