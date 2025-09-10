// 1733. Minimum Number of People to Teach
// https://leetcode.com/problems/minimum-number-of-people-to-teach/

#include <algorithm>
#include <bitset>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
    int m = languages.size();
    vector<bitset<501>> knownLanguages = vector<bitset<501>>(m + 1, bitset<501>());
    for (int f = 1; f <= m; ++f) {
      for (int l : languages[f - 1]) { knownLanguages[f].set(l); }
    }
    vector<vector<int>> graph = vector<vector<int>>(m + 1, vector<int>());
    for (const vector<int>& friendship : friendships) {
      graph[friendship[0]].push_back(friendship[1]);
      graph[friendship[1]].push_back(friendship[0]);
    }
    int ans = m;
    for (int l = 1; l <= n; ++l) {
      int curr = 0;
      vector<bool> visited(m + 1, false);
      for (int u = 1; u <= m; ++u) {
        for (int v : graph[u]) {
          if (visited[v]) { continue; }
          bitset<501> intersection = knownLanguages[u] & knownLanguages[v];
          if (intersection.count()) { continue; }
          if (!visited[u] && !knownLanguages[u].test(l)) {
            visited[u] = true;
            ++curr;
          }
          if (!visited[v] && !knownLanguages[v].test(l)) {
            visited[v] = true;
            ++curr;
          }
        }
      }
      ans = min(ans, curr);
    }
    return ans;
  }
};
