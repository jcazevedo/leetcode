// 925. Long Pressed Name
// https://leetcode.com/problems/long-pressed-name/

#include <string>

using namespace std;

class Solution {
 public:
  bool isLongPressedName(string name, string typed) {
    int i = 0, N = name.size(), T = typed.size();
    for (int j = 0; j < T; ++j) {
      if (i < N && name[i] == typed[j]) {
        ++i;
      } else if (j == 0 || typed[j] != typed[j - 1]) {
        return false;
      }
    }
    return i == N;
  }
};
