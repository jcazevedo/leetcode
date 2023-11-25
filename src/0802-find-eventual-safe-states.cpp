// 802. Find Eventual Safe States
// https://leetcode.com/problems/find-eventual-safe-states/

#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int N = graph.size();
    vector<int> inDegree(N, 0);
    vector<vector<int>> inverted(N, vector<int>());
    for (int i = 0; i < N; ++i) {
      for (unsigned int j = 0; j < graph[i].size(); ++j) {
        inverted[graph[i][j]].push_back(i);
        inDegree[i]++;
      }
    }
    queue<int> q;
    for (int i = 0; i < N; ++i) {
      if (inDegree[i] == 0) { q.push(i); }
    }
    vector<bool> safe(N, false);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      safe[u] = true;
      for (unsigned int i = 0; i < inverted[u].size(); ++i) {
        int v = inverted[u][i];
        inDegree[v]--;
        if (inDegree[v] == 0) { q.push(v); }
      }
    }
    vector<int> ans;
    for (int i = 0; i < N; ++i) {
      if (safe[i]) { ans.push_back(i); }
    }
    return ans;
  }
};
