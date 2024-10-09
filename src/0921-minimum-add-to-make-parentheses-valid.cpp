// 921. Minimum Add to Make Parentheses Valid
// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

#include <string>

using namespace std;

class Solution {
 public:
  int minAddToMakeValid(string s) {
    int ans = 0, curr = 0;
    for (const char& ch : s) {
      if (ch == ')') {
        if (curr == 0) {
          ++ans;
        } else {
          --curr;
        }
      } else if (ch == '(') {
        ++curr;
      }
    }
    ans += curr;
    return ans;
  }
};
