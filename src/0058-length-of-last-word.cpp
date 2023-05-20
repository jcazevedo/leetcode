// 58. Length of Last Word
// https://leetcode.com/problems/length-of-last-word/

#include <string>

using namespace std;

class Solution {
public:
  int lengthOfLastWord(string s) {
    int ans = 0, N = s.size();
    bool new_word = true;
    for (int i = 0; i < N; ++i) {
      if (s[i] == ' ')
        new_word = true;
      else if (new_word) {
        ans = 1;
        new_word = false;
      } else {
        ans++;
      }
    }
    return ans;
  }
};
