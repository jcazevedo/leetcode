// 2904. Shortest and Lexicographically Smallest Beautiful String
// https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/

#include <string>

using namespace std;

class Solution {
 public:
  string shortestBeautifulSubstring(string s, int k) {
    int l = 0, n = s.size(), cnt = 0, best_start = -1, best_length = 0;
    for (int r = 0; r < n; ++r) {
      if (s[r] == '1') { ++cnt; }
      if (cnt < k) { continue; }
      while (cnt > k || s[l] == '0') {
        if (s[l++] == '1') { --cnt; }
      }
      int len = r - l + 1;
      if (best_start == -1 || len < best_length ||
          (len == best_length && s.compare(l, len, s, best_start, best_length) < 0)) {
        best_start = l;
        best_length = len;
      }
    }
    return best_start == -1 ? "" : s.substr(best_start, best_length);
  }
};
