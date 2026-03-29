// 3884. First Matching Character From Both Ends
// https://leetcode.com/problems/first-matching-character-from-both-ends/

#include <string>

using namespace std;

class Solution {
 public:
  int firstMatchingIndex(string s) {
    int n = s.size();
    for (int i = 0; i < (n + 1) / 2; ++i) {
      if (s[i] == s[n - i - 1]) { return i; }
    }
    return -1;
  }
};
