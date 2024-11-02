// 2490. Circular Sentence
// https://leetcode.com/problems/circular-sentence/

#include <string>

using namespace std;

class Solution {
 public:
  bool isCircularSentence(string sentence) {
    int N = sentence.size();
    bool newWord = false;
    char last;
    for (int i = 0; i < N; ++i) {
      if (sentence[i] == ' ') {
        newWord = true;
      } else {
        if (newWord && sentence[i] != last) { return false; }
        newWord = false;
        last = sentence[i];
      }
    }
    return sentence[0] == sentence[N - 1];
  }
};
