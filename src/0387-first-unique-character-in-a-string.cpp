// 387. First Unique Character in a String
// https://leetcode.com/problems/first-unique-character-in-a-string/

#include <map>
#include <string>

using namespace std;

class Solution {
public:
  int firstUniqChar(string s) {
    int N = s.size();
    map<char, int> first_index;
    map<int, int> cnt;
    for (int i = 0; i < N; ++i) {
      if (first_index.find(s[i]) == first_index.end())
        first_index[s[i]] = i;
      cnt[first_index[s[i]]]++;
    }
    for (auto itr = cnt.begin(); itr != cnt.end(); ++itr) {
      if (itr->second == 1)
        return itr->first;
    }
    return -1;
  }
};
