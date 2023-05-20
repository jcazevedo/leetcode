// 139. Word Break
// https://leetcode.com/problems/word-break/

#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict;
    for (string word : wordDict)
      dict.insert(word);
    int N = s.size();
    vector<bool> possible(N + 1, false);
    possible[N] = true;
    for (int i = N - 1; i >= 0; --i) {
      if (!possible[i + 1])
        continue;
      for (int j = i; j >= 0; --j) {
        string word = s.substr(j, i - j + 1);
        if (dict.count(word) > 0)
          possible[j] = true;
      }
    }
    return possible[0];
  }
};
