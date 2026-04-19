// 925. Long Pressed Name
// https://leetcode.com/problems/long-pressed-name/

#include <string>

using namespace std;

class Solution {
 public:
  bool isLongPressedName(string name, string typed) {
    int N = name.size(), T = typed.size(), ni = 0, ti = 0;
    while (ni < N && ti < T) {
      if (name[ni] != typed[ti]) { return false; }
      int nc = 0, tc = 0;
      while (ni + 1 < N && name[ni + 1] == name[ni]) {
        ++ni;
        ++nc;
      }
      while (ti + 1 < T && typed[ti + 1] == typed[ti]) {
        ++ti;
        ++tc;
      }
      if (nc > tc) { return false; }
      ++ni;
      ++ti;
    }
    return ni >= N && ti >= T;
  }
};
