// 1790. Check if One String Swap Can Make Strings Equal
// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/

#include <map>
#include <string>

using namespace std;

class Solution {
 public:
  bool areAlmostEqual(string s1, string s2) {
    int n = s1.size();
    map<char, char> m;
    int diff = 0;
    for (int i = 0; i < n && diff <= 2; ++i) {
      if (s1[i] != s2[i]) {
        ++diff;
        m[s1[i]] = s2[i];
      }
    }
    if (diff != 0 && diff != 2) { return false; }
    return diff == 0 || (m.begin()->first == m.rbegin()->second && m.rbegin()->first == m.begin()->second);
  }
};
