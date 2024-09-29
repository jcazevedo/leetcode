// 884. Uncommon Words from Two Sentences
// https://leetcode.com/problems/uncommon-words-from-two-sentences/

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> uncommonFromSentences(string s1, string s2) {
    unordered_map<string, int> cnt1, cnt2;
    string word = "";
    for (char ch : s1) {
      if (ch == ' ') {
        if (!word.empty()) { ++cnt1[word]; }
        word = "";
      } else {
        word += ch;
      }
    }
    if (!word.empty()) { ++cnt1[word]; }
    word = "";
    for (char ch : s2) {
      if (ch == ' ') {
        if (!word.empty()) { ++cnt2[word]; }
        word = "";
      } else {
        word += ch;
      }
    }
    if (!word.empty()) { ++cnt2[word]; }
    vector<string> ans;
    for (unordered_map<string, int>::iterator itr = cnt1.begin(); itr != cnt1.end(); ++itr) {
      if (itr->second == 1 && cnt2[itr->first] == 0) { ans.push_back(itr->first); }
    }
    for (unordered_map<string, int>::iterator itr = cnt2.begin(); itr != cnt2.end(); ++itr) {
      if (itr->second == 1 && cnt1[itr->first] == 0) { ans.push_back(itr->first); }
    }
    return ans;
  }
};
