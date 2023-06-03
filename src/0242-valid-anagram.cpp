// 242. Valid Anagram
// https://leetcode.com/problems/valid-anagram/

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    int N = s.size();
    if ((int)t.size() != N)
      return false;
    unordered_map<char, int> counts;
    for (int i = 0; i < N; ++i)
      counts[s[i]]++;
    for (int i = 0; i < N; ++i)
      counts[t[i]]--;
    for (auto itr = counts.begin(); itr != counts.end(); ++itr)
      if (itr->second != 0)
        return false;
    return true;
  }
};
