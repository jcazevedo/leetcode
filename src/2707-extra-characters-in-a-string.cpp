// 2707. Extra Characters in a String
// https://leetcode.com/problems/extra-characters-in-a-string/

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int minExtraChar(string s, vector<string>& dictionary) {
    int N = s.size();
    vector<int> dp(N + 1, 0);
    for (int l = 1; l <= N; ++l) {
      dp[l] = dp[l - 1];
      for (string word : dictionary) {
        if ((int)word.size() <= l &&
            s.substr(l - word.size(), word.size()) == word) {
          dp[l] = max(dp[l], dp[l - word.size()] + (int)word.size());
        }
      }
    }
    return N - dp[N];
  }
};
