#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    string pre = "";
    int i = 0, N = strs.size();
    if (N == 0) return pre;
    while (true) {
      char ch = '_';
      for (int j = 0; j < N; ++j) {
        if ((int)strs[j].size() <= i) return pre;
        if (ch == '_' || ch == strs[j][i])
          ch = strs[j][i];
        else
          return pre;
      }
      ++i;
      pre += ch;
    }
  }
};
