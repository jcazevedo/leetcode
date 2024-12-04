// 2825. Make String a Subsequence Using Cyclic Increments
// https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/

#include <string>

using namespace std;

class Solution {
 public:
  bool canMakeSubsequence(string str1, string str2) {
    int N1 = str1.size(), N2 = str2.size(), i1 = 0;
    for (int i2 = 0; i2 < N2; ++i2) {
      while (i1 < N1 && str1[i1] != str2[i2] && ((str1[i1] - 'a' + 1) % 26 + 'a') != str2[i2]) { ++i1; }
      if (i1 == N1) { return false; }
      ++i1;
    }
    return true;
  }
};
