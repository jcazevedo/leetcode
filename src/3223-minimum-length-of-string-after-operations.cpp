// 3223. Minimum Length of String After Operations
// https://leetcode.com/problems/minimum-length-of-string-after-operations/

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumLength(string s) {
    int N = s.size();
    vector<vector<int>> cnt(26, vector<int>(N, 0));
    for (char ch = 'a'; ch <= 'z'; ++ch) {
      for (int i = 0; i < N; ++i) {
        if (i > 0) { cnt[ch - 'a'][i] = cnt[ch - 'a'][i - 1]; }
        if (s[i] == ch) { ++cnt[ch - 'a'][i]; }
      }
    }
    int ans = N;
    for (char ch = 'a'; ch <= 'z'; ++ch) {
      int best = 0;
      for (int i = 1; i < N - 1; ++i) {
        if (s[i] != ch) { continue; }
        int left = cnt[ch - 'a'][i - 1];
        int right = cnt[ch - 'a'][N - 1] - cnt[ch - 'a'][i];
        if (left > 0 && right > 0) { best = max(best, min(left, right) * 2); }
      }
      ans -= best;
    }
    return ans;
  }
};
