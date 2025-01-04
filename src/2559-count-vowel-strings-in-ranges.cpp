// 2559. Count Vowel Strings in Ranges
// https://leetcode.com/problems/count-vowel-strings-in-ranges/

#include <string>
#include <vector>

using namespace std;

class Solution {
 private:
  bool isVowel(char ch) { return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'; }

 public:
  vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
    int N = words.size();
    vector<int> p(N, 0);
    for (int i = 0; i < N; ++i) {
      if (i > 0) { p[i] = p[i - 1]; }
      if (isVowel(words[i][0]) && isVowel(words[i].back())) { ++p[i]; }
    }
    int Q = queries.size();
    vector<int> ans(Q);
    for (int i = 0; i < Q; ++i) {
      ans[i] = p[queries[i][1]];
      if (queries[i][0] > 0) { ans[i] -= p[queries[i][0] - 1]; }
    }
    return ans;
  }
};
