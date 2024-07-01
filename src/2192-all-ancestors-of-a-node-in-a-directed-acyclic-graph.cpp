// 2192. All Ancestors of a Node in a Directed Acyclic Graph
// https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/

#include <vector>

using namespace std;

class Solution {
 private:
  void dfs(int i, int u, vector<bool>& visited, const vector<vector<int>>& graph, vector<vector<int>>& ans) {
    for (int v : graph[u]) {
      if (!visited[v]) {
        visited[v] = true;
        ans[v].push_back(i);
        dfs(i, v, visited, graph, ans);
      }
    }
  }

 public:
  vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    vector<vector<int>> ans(n, vector<int>());
    vector<vector<int>> graph(n, vector<int>());
    for (const vector<int>& edge : edges) { graph[edge[0]].push_back(edge[1]); }

    for (int i = 0; i < n; ++i) {
      vector<bool> visited(n, false);
      visited[i] = true;
      dfs(i, i, visited, graph, ans);
    }
    return ans;
  }
};
