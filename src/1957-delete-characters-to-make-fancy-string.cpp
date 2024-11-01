// 1957. Delete Characters to Make Fancy String
// https://leetcode.com/problems/delete-characters-to-make-fancy-string/

#include <string>

using namespace std;

class Solution {
 public:
  string makeFancyString(string s) {
    string ans = "";
    int N = s.size();
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
      if (i > 0 && s[i] == s[i - 1]) {
        ++cnt;
      } else {
        cnt = 1;
      }
      if (cnt < 3) { ans += s[i]; }
    }
    return ans;
  }
};
