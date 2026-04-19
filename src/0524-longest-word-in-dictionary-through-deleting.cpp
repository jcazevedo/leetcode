// 524. Longest Word in Dictionary through Deleting
// https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string findLongestWord(string s, vector<string>& dictionary) {
    string ans = "";
    int S = s.size();
    for (const string& word : dictionary) {
      int W = word.size(), si = 0, wi = 0;
      while (si < S && wi < W) {
        if (s[si] == word[wi]) { ++wi; }
        ++si;
      }
      if (wi == W && (W > (int)ans.size() || (W == (int)ans.size() && word < ans))) { ans = word; }
    }
    return ans;
  }
};
