// 880. Decoded String at Index
// https://leetcode.com/problems/decoded-string-at-index/

#include <cstdio>
#include <string>

using namespace std;

class Solution {
 public:
  string decodeAtIndex(string s, int k) {
    int N = s.size();
    long long L = 0;

    for (int i = 0; i < N; ++i)
      if (isalpha(s[i]))
        L += 1;
      else
        L *= (s[i] - '0');

    for (int i = N - 1; i >= 0; --i) {
      k = k % L;

      if (k == 0 && isalpha(s[i])) return s.substr(i, 1);

      if (isalpha(s[i]))
        L -= 1;
      else { L /= (s[i] - '0'); }
    }

    return "";
  }
};
