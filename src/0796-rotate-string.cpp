// 796. Rotate String
// https://leetcode.com/problems/rotate-string/

#include <string>

using namespace std;

class Solution {
 public:
  bool rotateString(string s, string goal) {
    if (s.size() != goal.size()) { return false; }
    int N = s.size();
    for (int i = 0; i < N; ++i) {
      bool good = true;
      for (int l = 0; l < N; ++l) {
        if (s[l] != goal[(l + i) % N]) {
          good = false;
          break;
        }
      }
      if (good) { return true; }
    }
    return false;
  }
};
