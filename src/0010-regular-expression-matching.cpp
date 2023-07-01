// 10. Regular Expression Matching
// https://leetcode.com/problems/regular-expression-matching/

#include <string>
#include <vector>

using namespace std;

class Solution {
private:
  bool matches(int i, int j, const string& s, const string& p, vector<vector<short>>& cache) {
    if (cache[i][j] == -1) {
      bool good;
      if (j == (int)p.size())
        good = i == (int)s.size();
      else {
        bool currMatch = (i < (int)s.size() && (s[i] == p[j] || p[j] == '.'));
        if (j + 1 < (int)p.size() && p[j + 1] == '*')
          good = matches(i, j + 2, s, p, cache) || (currMatch && matches(i + 1, j, s, p, cache));
        else
          good = currMatch && matches(i + 1, j + 1, s, p, cache);
      }
      cache[i][j] = good ? 1 : 0;
    }
    return cache[i][j] == 1;
  }

public:
  bool isMatch(string s, string p) {
    vector<vector<short>> cache = vector<vector<short>>(s.size() + 1, vector<short>(p.size() + 1, -1));
    return matches(0, 0, s, p, cache);
  }
};
