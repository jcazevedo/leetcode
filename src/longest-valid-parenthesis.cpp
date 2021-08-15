#include <string>

using namespace std;

class Solution {
public:
  int longestValidParentheses(string s) {
    int N = s.size(), i = 0, j = 0, cnt = 0, ans = 0;
    while (j < N) {
      if (s[j] == '(')
        ++cnt;
      else if (cnt > 0) {
        --cnt;
        if (cnt == 0)
          ans = max(ans, j - i + 1);
      } else
        i = j + 1;
      ++j;
    }
    i = N - 1;
    j = N - 1;
    cnt = 0;
    while (i >= 0) {
      if (s[i] == ')')
        ++cnt;
      else if (cnt > 0) {
        --cnt;
        if (cnt == 0)
          ans = max(ans, j - i + 1);
      } else
        j = i - 1;
      --i;
    }
    return ans;
  }
};
