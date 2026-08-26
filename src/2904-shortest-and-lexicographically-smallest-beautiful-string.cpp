// 2904. Shortest and Lexicographically Smallest Beautiful String
// https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/

#include <string>

using namespace std;

class Solution {
 public:
  string shortestBeautifulSubstring(string s, int k) {
    string ans = "";
    int l = 0, n = s.size(), cnt = 0;
    for (int r = 0; r < n; ++r) {
      if (s[r] == '1') { ++cnt; }
      if (cnt >= k) {
        while (cnt > k || s[l] == '0') {
          if (s[l++] == '1') { --cnt; }
        }
        int len = r - l + 1;
        string curr = s.substr(l, len);
        if (ans.size() == 0 || len < (int)ans.size() || (len == (int)ans.size() && curr < ans)) { ans = curr; }
      }
    }
    return ans;
  }
};
