// 1190. Reverse Substrings Between Each Pair of Parentheses
// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/

#include <algorithm>
#include <stack>
#include <string>

using namespace std;

class Solution {
 public:
  string reverseParentheses(string s) {
    string ans = "";
    stack<int> starts;
    for (char ch : s)
      if (ch == '(')
        starts.push(ans.size());
      else if (ch == ')') {
        int start = starts.top();
        starts.pop();
        if (start < (int)ans.size()) {
          string toReverse = ans.substr(start, ans.size() - start);
          reverse(toReverse.begin(), toReverse.end());
          ans = ans.substr(0, start) + toReverse;
        }
      } else
        ans += ch;
    return ans;
  }
};
