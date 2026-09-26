// 1807. Evaluate the Bracket Pairs of a String
// https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  string evaluate(string s, vector<vector<string>>& knowledge) {
    unordered_map<string, string> knowledgeMap;
    for (const vector<string>& knowledgePair : knowledge) { knowledgeMap[knowledgePair[0]] = knowledgePair[1]; }
    string ans = "";
    int n = s.size();
    string key = "";
    bool inKey = false;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '(') {
        inKey = true;
        key = "";
      } else if (s[i] == ')') {
        if (knowledgeMap.find(key) != knowledgeMap.end()) {
          ans += knowledgeMap[key];
        } else {
          ans += "?";
        }
        inKey = false;
      } else if (inKey) {
        key += s[i];
      } else {
        ans += s[i];
      }
    }
    return ans;
  }
};
