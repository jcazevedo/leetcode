// 557. Reverse Words in a String III
// https://leetcode.com/problems/reverse-words-in-a-string-iii/

#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
  string reverseWords(string s) {
    int N = s.size();
    int wordStart = 0;
    for (int i = 0; i < N; ++i)
      if (s[i] == ' ') {
        for (int j = 0; j < (i - wordStart) / 2; ++j)
          swap(s[wordStart + j], s[wordStart + i - wordStart - 1 - j]);
        wordStart = i + 1;
      }
    for (int i = 0; i < (N - wordStart) / 2; ++i)
      swap(s[wordStart + i], s[wordStart + N - wordStart - 1 - i]);
    return s;
  }
};
