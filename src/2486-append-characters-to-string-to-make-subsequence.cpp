// 2486. Append Characters to String to Make Subsequence
// https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/

#include <algorithm>
#include <string>

using namespace std;

class Solution {
 public:
  int appendCharacters(string s, string t) {
    int S = s.size(), T = t.size(), ti = 0;
    for (int si = 0; si < S; ++si) {
      if (ti < T && s[si] == t[ti]) { ++ti; }
    }
    return max(0, T - ti);
  }
};
