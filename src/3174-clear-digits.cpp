// 3174. Clear Digits
// https://leetcode.com/problems/clear-digits/

#include <cstdio>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string clearDigits(string s) {
    int n = s.size();
    vector<bool> toDelete(n, false);
    for (int i = n - 1; i >= 0; --i) {
      if (isdigit(s[i])) {
        toDelete[i] = true;
        for (int j = i - 1; j >= 0; --j) {
          if (toDelete[j]) { continue; }
          if (isdigit(s[j])) { continue; }
          toDelete[j] = true;
          break;
        }
      }
    }
    string ans = "";
    for (int i = 0; i < n; ++i) {
      if (toDelete[i]) { continue; }
      ans += s[i];
    }
    return ans;
  }
};
