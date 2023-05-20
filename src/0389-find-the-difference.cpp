// 389. Find the Difference
// https://leetcode.com/problems/find-the-difference/

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  char findTheDifference(string s, string t) {
    unordered_map<char, int> cnt;
    for (char c : t)
      cnt[c]++;
    for (char c : s)
      cnt[c]--;
    for (auto itr = cnt.begin(); itr != cnt.end(); ++itr) {
      if (itr->second != 0)
        return itr->first;
    }
    return -1;
  }
};
