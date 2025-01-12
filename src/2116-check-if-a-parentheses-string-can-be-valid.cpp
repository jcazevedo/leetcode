// 2116. Check if a Parentheses String Can Be Valid
// https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/

#include <stack>
#include <string>

using namespace std;

class Solution {
 public:
  bool canBeValid(string s, string locked) {
    int N = s.size();
    stack<int> open, unlocked;
    for (int i = 0; i < N; ++i) {
      if (locked[i] == '0') {
        unlocked.push(i);
      } else if (s[i] == '(') {
        open.push(i);
      } else if (s[i] == ')') {
        if (!open.empty()) {
          open.pop();
        } else if (!unlocked.empty()) {
          unlocked.pop();
        } else {
          return false;
        }
      }
    }
    while (!open.empty() && !unlocked.empty() && open.top() < unlocked.top()) {
      open.pop();
      unlocked.pop();
    }
    if (!open.empty()) { return false; }
    return unlocked.size() % 2 == 0;
  }
};
