// 290. Word Pattern
// https://leetcode.com/problems/word-pattern/

#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 private:
  vector<string> split(string str) {
    istringstream ss(str);
    vector<string> ans;
    string curr;
    while (ss >> curr) ans.push_back(curr);
    return ans;
  }

 public:
  bool wordPattern(string pattern, string str) {
    vector<string> words = split(str);
    if (words.size() != pattern.size()) return false;
    unordered_map<string, char> pat;
    set<char> used;
    int N = words.size();
    for (int i = 0; i < N; ++i) {
      if (pat.find(words[i]) != pat.end() && pat[words[i]] != pattern[i]) return false;
      pat[words[i]] = pattern[i];
      used.insert(pattern[i]);
    }
    return pat.size() == used.size();
  }
};
