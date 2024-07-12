// 1717. Maximum Score From Removing Substrings
// https://leetcode.com/problems/maximum-score-from-removing-substrings/

#include <algorithm>
#include <stack>
#include <string>

using namespace std;

class Solution {
 public:
  int maximumGain(string s, int x, int y) {
    int ans = 0, s1 = max(x, y), s2 = min(x, y);
    if (y > x) reverse(s.begin(), s.end());
    stack<char> st;
    for (char ch : s)
      if (!st.empty() && st.top() == 'a' && ch == 'b') {
        st.pop();
        ans += s1;
      } else
        st.push(ch);
    s = "";
    while (!st.empty()) {
      s += st.top();
      st.pop();
    }
    for (char ch : s) {
      if (!st.empty() && st.top() == 'a' && ch == 'b') {
        st.pop();
        ans += s2;
      } else
        st.push(ch);
    }
    return ans;
  }
};
