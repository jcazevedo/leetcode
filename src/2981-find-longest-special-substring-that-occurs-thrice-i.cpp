// 2981. Find Longest Special Substring That Occurs Thrice I
// https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/

#include <algorithm>
#include <string>

using namespace std;

class Solution {
 public:
  int maximumLength(string s) {
    int N = s.size();
    int ans = -1;
    for (char ch = 'a'; ch <= 'z'; ++ch) {
      for (int l = 1; l <= N; ++l) {
        int cnt = 0;
        for (int i = 0; i + l <= N; ++i) {
          bool good = true;
          for (int j = 0; j < l && good; ++j) {
            if (s[i + j] != ch) { good = false; }
          }
          if (good) { ++cnt; }
        }
        if (cnt >= 3) { ans = max(ans, l); }
      }
    }
    return ans;
  }
};
