// 1408. String Matching in an Array
// https://leetcode.com/problems/string-matching-in-an-array/

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> stringMatching(vector<string>& words) {
    vector<string> ans;
    for (const string& word1 : words) {
      for (const string& word2 : words) {
        if (word1 == word2) { continue; }
        if (word2.find(word1) != string::npos) {
          ans.push_back(word1);
          break;
        }
      }
    }
    return ans;
  }
};
