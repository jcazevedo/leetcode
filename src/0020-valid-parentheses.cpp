// 20. Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/

#include <stack>
#include <string>

using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    stack<char> st;
    for (char ch : s) {
      if (ch == '}' && (st.empty() || st.top() != '{')) return false;
      if (ch == ')' && (st.empty() || st.top() != '(')) return false;
      if (ch == ']' && (st.empty() || st.top() != '[')) return false;
      if (ch == '}' || ch == ')' || ch == ']')
        st.pop();
      else
        st.push(ch);
    }
    return st.empty();
  }
};
