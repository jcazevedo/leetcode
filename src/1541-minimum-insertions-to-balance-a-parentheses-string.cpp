// 1541. Minimum Insertions to Balance a Parentheses String
// https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/

#include <string>

using namespace std;

class Solution {
 public:
  int minInsertions(string s) {
    int n = s.size();
    int balance = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '(') { ++balance; }
      if (s[i] == ')') {
        if (balance == 0) {
          ++ans;
        } else {
          --balance;
        }
        if (i == n - 1 || s[i + 1] != ')') {
          ++ans;
        } else {
          ++i;
        }
      }
    }
    return ans + balance * 2;
  }
};
