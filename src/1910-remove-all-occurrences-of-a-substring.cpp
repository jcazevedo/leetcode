// 1910. Remove All Occurrences of a Substring
// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/

#include <string>

using namespace std;

class Solution {
 public:
  string removeOccurrences(string s, string part) {
    while (true) {
      size_t idx = s.find(part);
      if (idx != string::npos) {
        s = s.substr(0, idx) + s.substr(idx + part.size());
      } else {
        break;
      }
    }
    return s;
  }
};
