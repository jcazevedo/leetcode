// 1358. Number of Substrings Containing All Three Characters
// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int numberOfSubstrings(string s) {
    int n = s.size();
    unordered_map<char, int> cnt;
    int ans = 0, st = 0;
    for (int i = 0; i < n; ++i) {
      ++cnt[s[i]];
      while (cnt['a'] && cnt['b'] && cnt['c'] && st <= i) {
        ans += n - i;
        --cnt[s[st++]];
      }
    }
    return ans;
  }
};
