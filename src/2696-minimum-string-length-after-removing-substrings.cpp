// 2696. Minimum String Length After Removing Substrings
// https://leetcode.com/problems/minimum-string-length-after-removing-substrings/

#include <string>

using namespace std;

class Solution {
 public:
  int minLength(string s) {
    while (true) {
      size_t ab = s.find("AB");
      bool good = false;
      if (ab != string::npos) {
        good = true;
        s = s.substr(0, ab) + s.substr(ab + 2);
      }
      size_t cd = s.find("CD");
      if (cd != string::npos) {
        good = true;
        s = s.substr(0, cd) + s.substr(cd + 2);
      }
      if (!good) { break; }
    }
    return s.size();
  }
};
