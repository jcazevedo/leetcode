// 2493. Divide Nodes Into the Maximum Number of Groups
// https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups/

#include <algorithm>
#include <cmath>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
 private:
  int bfs(int start, const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> groups(n, -1);
    queue<tuple<int, int>> q;
    groups[start] = 1;
    q.push({start, 1});
    int ans = 0;
    while (!q.empty()) {
      tuple<int, int> curr = q.front();
      q.pop();
      int node = get<0>(curr);
      int group = get<1>(curr);
      ans = max(ans, group);
      for (int next : graph[node]) {
        if (groups[next] != -1) {
          if (abs(groups[next] - group) != 1) { return -1; }
          continue;
        }
        groups[next] = group + 1;
        q.push({next, group + 1});
      }
    }
    return ans;
  }

  int maxGroups(int node, const vector<int>& groupsFrom, const vector<vector<int>>& graph, vector<bool>& visited) {
    int g = groupsFrom[node];
    visited[node] = true;
    for (int next : graph[node]) {
      if (visited[next]) { continue; }
      g = max(g, maxGroups(next, groupsFrom, graph, visited));
    }
    return g;
  }

 public:
  int magnificentSets(int n, vector<vector<int>>& edges) {
    vector<vector<int>> graph(n + 1, vector<int>());
    for (const vector<int>& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }
    vector<int> groupsFrom(n + 1, -1);
    for (int i = 1; i <= n; ++i) {
      groupsFrom[i] = bfs(i, graph);
      if (groupsFrom[i] == -1) { return -1; }
    }
    int ans = 0;
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; ++i) {
      if (visited[i]) { continue; }
      ans += maxGroups(i, groupsFrom, graph, visited);
    }
    return ans;
  }
};
