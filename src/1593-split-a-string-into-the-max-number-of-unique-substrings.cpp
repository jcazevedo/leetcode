// 1593. Split a String Into the Max Number of Unique Substrings
// https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/

#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  int maxUniqueSplit(string s) {
    int N = s.size();
    int ans = 0;
    for (int sol = 0; sol < (1 << (N - 1)); ++sol) {
      string curr = string(1, s[0]);
      unordered_set<string> substrings;
      int cnt = 0;
      for (int i = 1; i < N; ++i) {
        if (sol & (1 << (i - 1))) {
          substrings.insert(curr);
          ++cnt;
          curr = "";
        }
        curr += s[i];
      }
      substrings.insert(curr);
      ++cnt;
      if (cnt == (int)substrings.size()) { ans = max(ans, cnt); }
    }
    return ans;
  }
};
