#include <string>

using namespace std;

class Solution {
public:
  bool isSubsequence(string s, string t) {
    int S = s.size(), T = t.size();
    int j = 0;
    for (int i = 0; i < S; ++i) {
      while (j < T && t[j] != s[i])
        ++j;
      if (j >= T)
        return false;
      ++j;
    }
    return true;
  }
};
