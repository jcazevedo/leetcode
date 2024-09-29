// 1684. Count the Number of Consistent Strings
// https://leetcode.com/problems/count-the-number-of-consistent-strings/

#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int countConsistentStrings(string allowed, vector<string>& words) {
    unordered_set<char> allowedSet;
    for (char ch : allowed) { allowedSet.insert(ch); }
    int ans = 0;
    for (const string& word : words) {
      bool good = true;
      for (const char& ch : word) {
        if (allowedSet.find(ch) == allowedSet.end()) {
          good = false;
          break;
        }
      }
      if (good) { ++ans; }
    }
    return ans;
  }
};
