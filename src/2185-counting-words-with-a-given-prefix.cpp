// 2185. Counting Words With a Given Prefix
// https://leetcode.com/problems/counting-words-with-a-given-prefix/

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int prefixCount(vector<string>& words, string pref) {
    int ans = 0;
    for (const string& word : words) {
      if (word.size() >= pref.size() && word.substr(0, pref.size()) == pref) { ++ans; }
    }
    return ans;
  }
};
