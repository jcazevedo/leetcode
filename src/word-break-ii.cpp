#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
private:
  string line;
  int N;
  vector<vector<int>> can_go;
  vector<bool> visited;
  vector<vector<string>> dp;

  vector<string> dfs(int i) {
    if (i >= N)
      return {""};
    if (visited[i])
      return dp[i];
    visited[i] = true;
    vector<string> ans;
    for (int j : can_go[i]) {
      string word = line.substr(i, j - i);
      if (j == N)
        ans.push_back(word);
      else {
        vector<string> next = dfs(j);
        for (string n : next)
          ans.push_back(word + " " + n);
      }
    }
    return dp[i] = ans;
  }

public:
  vector<string> wordBreak(string s, vector<string> &wordDict) {
    line = s;
    unordered_set<string> words;
    for (string word : wordDict)
      words.insert(word);
    N = s.size();
    can_go.assign(N, vector<int>());
    for (int i = 0; i < N; ++i) {
      for (int j = i; j < N; ++j) {
        string word = s.substr(i, j - i + 1);
        if (words.count(word) > 0)
          can_go[i].push_back(j + 1);
      }
    }
    visited.assign(N, false);
    dp.assign(N, vector<string>());
    return dfs(0);
  }
};
