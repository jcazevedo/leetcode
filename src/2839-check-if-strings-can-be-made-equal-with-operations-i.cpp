// 2839. Check if Strings Can be Made Equal With Operations I
// https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/

#include <algorithm>
#include <string>

using namespace std;

class Solution {
 public:
  bool canBeEqual(string s1, string s2) {
    int n = 4;
    for (int i = 0; i + 2 < n; ++i) {
      if (s1[i] > s1[i + 2]) { swap(s1[i], s1[i + 2]); }
      if (s2[i] > s2[i + 2]) { swap(s2[i], s2[i + 2]); }
    }
    return s1 == s2;
  }
};
