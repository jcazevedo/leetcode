// 2124. Check if All A's Appears Before All B's
// https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/

#include <string>

using namespace std;

class Solution {
 public:
  bool checkString(string s) {
    bool hasB = false;
    for (char ch : s) {
      if (ch == 'a' && hasB) { return false; }
      if (ch == 'b') { hasB = true; }
    }
    return true;
  }
};
