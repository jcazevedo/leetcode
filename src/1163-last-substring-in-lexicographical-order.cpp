// 1163. Last Substring in Lexicographical Order
// https://leetcode.com/problems/last-substring-in-lexicographical-order/

#include <string>

using namespace std;

class Solution {
 public:
  string lastSubstring(string s) {
    int i = 0, k = 0, j = 1, N = s.size();
    while (j + k < N) {
      if (s[i + k] == s[j + k]) {
        k++;
        continue;
      }
      if (s[i + k] > s[j + k]) {
        j = j + k + 1;
      } else {
        i = j;
        j = i + 1;
      }
      k = 0;
    }
    return s.substr(i);
  }
};
