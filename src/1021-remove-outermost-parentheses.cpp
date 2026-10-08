// 1021. Remove Outermost Parentheses
// https://leetcode.com/problems/remove-outermost-parentheses/

#include <string>

using namespace std;

class Solution {
 public:
  string removeOuterParentheses(string s) {
    string ans = "";
    int n = s.size();
    int balance = 0;
    int prev = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '(') {
        if (balance == 0) { prev = i; }
        ++balance;
      }
      if (s[i] == ')') {
        --balance;
        if (balance == 0) { ans += s.substr(prev + 1, i - prev - 1); }
      }
    }
    return ans;
  }
};
