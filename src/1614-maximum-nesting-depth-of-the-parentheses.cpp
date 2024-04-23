// 1614. Maximum Nesting Depth of the Parentheses
// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

#include <algorithm>
#include <string>

using namespace std;

class Solution {
 public:
  int maxDepth(string s) {
    int ans = 0, curr = 0;
    for (const char& ch : s) {
      if (ch == '(')
        ++curr;
      else if (ch == ')')
        --curr;
      ans = max(ans, curr);
    }
    return ans;
  }
};
