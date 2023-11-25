// 30. Substring with Concatenation of All Words
// https://leetcode.com/problems/substring-with-concatenation-of-all-words/

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 private:
  bool good(int si,
            unordered_map<string, int> count,
            const string& s,
            int wordLen,
            int wordsLen) {
    for (int i = 0; i < wordsLen; i += wordLen) {
      string curr = s.substr(i + si, wordLen);
      if (count[curr] == 0) return false;
      count[curr]--;
    }
    return true;
  }

 public:
  vector<int> findSubstring(string s, vector<string>& words) {
    unordered_map<string, int> count;
    for (string word : words) count[word]++;
    int wordsLen = words[0].size() * words.size();
    vector<int> ans;
    for (int i = 0; i + wordsLen <= (int)s.size(); ++i) {
      if (good(i, count, s, words[0].size(), wordsLen)) ans.push_back(i);
    }
    return ans;
  }
};
