// 3474. Lexicographically Smallest Generated String
// https://leetcode.com/problems/lexicographically-smallest-generated-string/

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string generateString(string str1, string str2) {
    int n = str1.size(), m = str2.size();
    string ans(n + m - 1, 'a');
    vector<bool> forced(n + m - 1, false);
    for (int i = 0; i < n; ++i) {
      if (str1[i] == 'T') {
        for (int j = i; j < i + m; ++j) {
          if (forced[j] && ans[j] != str2[j - i]) { return ""; }
          ans[j] = str2[j - i];
          forced[j] = true;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      if (str1[i] == 'F') {
        bool match = true;
        for (int j = i; j < i + m; ++j) {
          if (ans[j] != str2[j - i]) {
            match = false;
            break;
          }
        }
        if (match) {
          bool found = false;
          for (int j = i + m - 1; j >= i && !found; --j) {
            if (!forced[j]) {
              ans[j] = (char)(ans[j] + 1);
              found = true;
            }
          }
          if (!found) { return ""; }
        }
      }
    }
    return ans;
  }
};
