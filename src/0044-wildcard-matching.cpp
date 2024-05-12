// 44. Wildcard Matching
// https://leetcode.com/problems/wildcard-matching/

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isMatch(string s, string p) {
    int S = s.size(), P = p.size();
    vector<vector<bool>> matches(S + 1, vector<bool>(P + 1, false));
    matches[0][0] = true;
    for (int j = 1; j <= P; ++j)
      if (p[j - 1] == '*') matches[0][j] = matches[0][j - 1];
    for (int i = 1; i <= S; ++i)
      for (int j = 1; j <= P; ++j)
        if (p[j - 1] == '?')
          matches[i][j] = matches[i - 1][j - 1];
        else if (p[j - 1] == '*')
          matches[i][j] = matches[i - 1][j] || matches[i][j - 1];
        else
          matches[i][j] = s[i - 1] == p[j - 1] && matches[i - 1][j - 1];
    return matches[S][P];
  }
};
