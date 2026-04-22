// 2452. Words Within Two Edits of Dictionary
// https://leetcode.com/problems/words-within-two-edits-of-dictionary/

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
    int n = queries[0].size();
    vector<string> ans;
    for (const string& q : queries) {
      for (const string& d : dictionary) {
        int diff = 0;
        for (int i = 0; i < n && diff <= 2; ++i) {
          if (q[i] != d[i]) { ++diff; }
        }
        if (diff <= 2) {
          ans.push_back(q);
          break;
        }
      }
    }
    return ans;
  }
};
