// 205. Isomorphic Strings
// https://leetcode.com/problems/isomorphic-strings/

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool isIsomorphic(string s, string t) {
    if (s.size() != t.size())
      return false;
    int N = s.size();
    unordered_map<char, char> mapping, reverseMapping;
    for (int i = 0; i < N; ++i) {
      if (mapping.find(s[i]) != mapping.end() && mapping[s[i]] != t[i])
        return false;
      if (reverseMapping.find(t[i]) != reverseMapping.end() && reverseMapping[t[i]] != s[i])
        return false;
      mapping[s[i]] = t[i];
      reverseMapping[t[i]] = s[i];
    }
    return true;
  }
};
