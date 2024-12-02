// 1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence
// https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/

#include <string>

using namespace std;

class Solution {
 public:
  int isPrefixOfWord(string sentence, string searchWord) {
    int N = sentence.size();
    bool good = true;
    int wi = 1, si = 0;
    for (int i = 0; i < N; ++i) {
      if (sentence[i] == ' ') {
        good = true;
        si = 0;
        ++wi;
      } else if (good && si < (int)searchWord.size() && sentence[i] == searchWord[si]) {
        ++si;
        if (si == (int)searchWord.size()) { return wi; }
      } else {
        good = false;
      }
    }
    return -1;
  }
};
