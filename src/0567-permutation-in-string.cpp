// 567. Permutation in String
// https://leetcode.com/problems/permutation-in-string/

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 private:
  bool is_anagram(unordered_map<char, int>& current, unordered_map<char, int>& expected) {
    for (unordered_map<char, int>::iterator itr = expected.begin(); itr != expected.end(); ++itr) {
      if (current[itr->first] != itr->second) return false;
    }
    return true;
  }

 public:
  bool checkInclusion(string p, string s) {
    unordered_map<char, int> expected;
    for (char ch : p) expected[ch]++;
    unordered_map<char, int> cnt;
    int S = s.size(), P = p.size();
    if (S >= P) {
      for (int i = 0; i < P; ++i) cnt[s[i]]++;
      for (int i = 0; i + P <= S; ++i) {
        if (is_anagram(cnt, expected)) return true;
        cnt[s[i]]--;
        if (i + P < S) cnt[s[i + P]]++;
      }
    }
    return false;
  }
};
