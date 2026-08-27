// 3720. Lexicographically Smallest Permutation Greater Than Target
// https://leetcode.com/problems/lexicographically-smallest-permutation-greater-than-target/

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  string lexGreaterPermutation(string s, string target) {
    int n = s.size();
    for (int i = n - 1; i >= 0; --i) {
      unordered_map<char, int> cnt;
      for (char ch : s) { ++cnt[ch]; }
      bool possible = true;
      for (int j = 0; j < i; ++j) {
        if (cnt[target[j]] == 0) {
          possible = false;
          break;
        }
        --cnt[target[j]];
      }
      if (!possible) { continue; }
      char next = target[i] + 1;
      while (next <= 'z' && cnt[next] == 0) { ++next; }
      if (next > 'z') { continue; }
      string ans = target.substr(0, i);
      ans += next;
      --cnt[next];
      for (char ch = 'a'; ch <= 'z'; ++ch) { ans += string(cnt[ch], ch); }
      return ans;
    }
    return "";
  }
};
