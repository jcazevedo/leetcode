// 28. Implement strStr()
// https://leetcode.com/problems/implement-strstr/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int strStr(string haystack, string needle) {
    if (needle.size() == 0)
      return 0;

    if (needle.size() > haystack.size())
      return -1;

    vector<int> T = vector<int>(needle.size(), 0);

    int len = 0, j = 1;
    T[0] = 0;
    while (j < (int)needle.size()) {
      if (needle[j] == needle[len]) {
        ++len;
        T[j] = len;
        ++j;
      } else if (len != 0) {
        len = T[len - 1];
      } else {
        T[j] = 0;
        ++j;
      }
    }

    int i = 0;
    j = 0;
    while (i < (int)haystack.size()) {
      if (needle[j] == haystack[i]) {
        ++i;
        ++j;
      }

      if (j == (int)needle.size())
        return i - j;
      else if (i < (int)haystack.size() && needle[j] != haystack[i]) {
        if (j != 0)
          j = T[j - 1];
        else
          ++i;
      }
    }

    return -1;
  }
};
