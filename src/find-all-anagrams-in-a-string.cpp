#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
 private:
  bool is_anagram(map<char, int>& current, map<char, int>& expected) {
    for (auto itr = expected.begin(); itr != expected.end(); ++itr) {
      if (current[itr->first] != itr->second) return false;
    }
    return true;
  }

 public:
  vector<int> findAnagrams(string s, string p) {
    map<char, int> expected;
    for (char ch : p) expected[ch]++;
    map<char, int> cnt;
    int S = s.size(), P = p.size();
    ;
    vector<int> res;
    if (S >= P) {
      for (int i = 0; i < P; ++i) cnt[s[i]]++;
      for (int i = 0; i + P <= S; ++i) {
        if (is_anagram(cnt, expected)) res.push_back(i);
        cnt[s[i]]--;
        if (i + P < S) cnt[s[i + P]]++;
      }
    }
    return res;
  }
};
