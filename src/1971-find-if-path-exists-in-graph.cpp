// 1971. Find if Path Exists in Graph
// https://leetcode.com/problems/find-if-path-exists-in-graph/

#include <vector>

using namespace std;

class Solution {
 private:
  bool dfs(int source, int destination, const vector<vector<int>>& graph, vector<bool>& visited) {
    if (source == destination) return true;
    for (int v : graph[source])
      if (!visited[v]) {
        visited[v] = true;
        if (dfs(v, destination, graph, visited)) return true;
      }
    return false;
  }

 public:
  bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    vector<vector<int>> graph(n, vector<int>());
    for (const vector<int>& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }
    vector<bool> visited(n, false);
    visited[source] = true;
    return dfs(source, destination, graph, visited);
  }
};
