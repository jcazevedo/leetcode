// 3335. Total Characters in String After Transformations I
// https://leetcode.com/problems/total-characters-in-string-after-transformations-i/

#include <string>
#include <vector>

using namespace std;

#define MOD 1000000007L
#define MAXA 26

class Solution {
 public:
  int lengthAfterTransformations(string s, int t) {
    vector<vector<int>> cache(MAXA, vector<int>(t + 1));
    for (int ch = 0; ch < MAXA; ++ch) { cache[ch][0] = 1; }
    for (int tt = 1; tt <= t; ++tt) {
      for (int ch = 0; ch < MAXA - 1; ++ch) { cache[ch][tt] = cache[ch + 1][tt - 1]; }
      cache[MAXA - 1][tt] = (cache[0][tt - 1] + cache[1][tt - 1]) % MOD;
    }
    long long ans = 0L;
    for (char ch : s) { ans = (ans + cache[ch - 'a'][t]) % MOD; }
    return ans;
  }
};
