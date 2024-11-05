// 2914. Minimum Number of Changes to Make Binary String Beautiful
// https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/

#include <string>

using namespace std;

class Solution {
 public:
  int minChanges(string s) {
    int ans = 0;
    int N = s.size();
    for (int i = 1; i < N; i += 2) {
      if (s[i] != s[i - 1]) { ++ans; }
    }
    return ans;
  }
};
