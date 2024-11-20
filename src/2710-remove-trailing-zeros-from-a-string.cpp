// 2710. Remove Trailing Zeros From a String
// https://leetcode.com/problems/remove-trailing-zeros-from-a-string/

#include <string>

using namespace std;

class Solution {
 public:
  string removeTrailingZeros(string num) {
    while (num.back() == '0') { num.pop_back(); }
    return num;
  }
};
