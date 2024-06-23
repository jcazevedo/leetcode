// 1657. Determine if Two Strings Are Close
// https://leetcode.com/problems/determine-if-two-strings-are-close/

#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool closeStrings(string word1, string word2) {
    map<char, int> cnt1, cnt2;
    for (char ch : word1) cnt1[ch]++;
    for (char ch : word2) cnt2[ch]++;
    for (auto itr = cnt1.begin(); itr != cnt1.end(); ++itr)
      if (cnt2.find(itr->first) == cnt2.end()) return false;
    for (auto itr = cnt2.begin(); itr != cnt2.end(); ++itr)
      if (cnt1.find(itr->first) == cnt1.end()) return false;
    vector<int> tot1, tot2;
    for (auto itr = cnt1.begin(); itr != cnt1.end(); ++itr) tot1.push_back(itr->second);
    for (auto itr = cnt2.begin(); itr != cnt2.end(); ++itr) tot2.push_back(itr->second);
    sort(tot1.begin(), tot1.end());
    sort(tot2.begin(), tot2.end());
    return tot1 == tot2;
  }
};
