// 856. Score of Parentheses
// https://leetcode.com/problems/score-of-parentheses/

#include <algorithm>
#include <stack>
#include <string>

using namespace std;

class Solution {
 public:
  int scoreOfParentheses(string s) {
    stack<int> scores;
    scores.push(0);
    for (const char& ch : s) {
      if (ch == '(') { scores.push(0); }
      if (ch == ')') {
        int curr = scores.top();
        scores.pop();
        scores.top() += max(1, curr * 2);
      }
    }
    return scores.top();
  }
};
