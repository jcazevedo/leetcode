// 2000. Reverse Prefix of Word
// https://leetcode.com/problems/reverse-prefix-of-word/

#include <algorithm>
#include <string>

using namespace std;

class Solution {
 public:
  string reversePrefix(string word, char ch) {
    int N = word.size();
    for (int i = 0; i < N; ++i)
      if (word[i] == ch) {
        for (int j = 0; j < (i + 1) / 2; ++j) swap(word[j], word[i - j]);
        break;
      }
    return word;
  }
};
