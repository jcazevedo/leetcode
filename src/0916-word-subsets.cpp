// 916. Word Subsets
// https://leetcode.com/problems/word-subsets/

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    int W2 = words2.size();
    vector<vector<int>> cnt(26, vector<int>(11));
    for (int i = 0; i < W2; ++i) {
      unordered_map<char, int> wcnt;
      for (char ch : words2[i]) { ++wcnt[ch]; }
      for (char ch = 'a'; ch <= 'z'; ++ch) { ++cnt[ch - 'a'][wcnt[ch]]; }
    }
    for (char ch = 'a'; ch <= 'z'; ++ch) {
      for (int l = 1; l <= 10; ++l) { cnt[ch - 'a'][l] += cnt[ch - 'a'][l - 1]; }
    }
    vector<string> ans;
    for (const string& word : words1) {
      unordered_map<char, int> wcnt;
      for (char ch : word) { ++wcnt[ch]; }
      bool good = true;
      for (char ch = 'a'; ch <= 'z' && good; ++ch) {
        if (cnt[ch - 'a'][wcnt[ch]] != W2) { good = false; }
      }
      if (good) { ans.push_back(word); }
    }
    return ans;
  }
};
