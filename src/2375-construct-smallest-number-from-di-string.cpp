// 2375. Construct Smallest Number From DI String
// https://leetcode.com/problems/construct-smallest-number-from-di-string/

#include <string>
#include <vector>

using namespace std;

class Solution {
 private:
  bool go(string& ans, int i, int n, string& pattern, vector<bool>& used) {
    if (i >= n) { return true; }
    int s, e;
    if (i == 0) {
      s = 1;
      e = 9;
    } else if (pattern[i - 1] == 'I') {
      s = ans[i - 1] - '0' + 1;
      e = 9;
    } else {
      s = 1;
      e = ans[i - 1] - '0' - 1;
    }
    for (int d = s; d <= e; ++d) {
      if (used[d]) { continue; }
      ans[i] = d + '0';
      used[d] = true;
      if (go(ans, i + 1, n, pattern, used)) { return true; }
      used[d] = false;
    }
    return false;
  }

 public:
  string smallestNumber(string pattern) {
    int n = pattern.size();
    string ans(n + 1, ' ');
    vector<bool> used(10, false);
    go(ans, 0, n + 1, pattern, used);
    return ans;
  }
};
