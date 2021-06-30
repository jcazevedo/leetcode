#include <vector>

using namespace std;

class Solution {
private:
  vector<int> dist;
  vector<int> parent;

  void dfs(int u, const vector<vector<int>> &graph) {
    for (int v : graph[u]) {
      if (dist[v] != -1)
        continue;
      dist[v] = dist[u] + 1;
      parent[v] = u;
      dfs(v, graph);
    }
  }

public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
    vector<vector<int>> graph = vector<vector<int>>(n, vector<int>());
    for (const vector<int> &edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }
    dist.assign(n, -1);
    parent.assign(n, -1);
    dist[0] = 0;
    dfs(0, graph);
    int left = 0;
    for (int i = 1; i < n; ++i) {
      if (dist[i] > dist[left])
        left = i;
    }
    dist.assign(n, -1);
    parent.assign(n, -1);
    dist[left] = 0;
    dfs(left, graph);
    int right = 0;
    for (int i = 1; i < n; ++i) {
      if (dist[i] > dist[right])
        right = i;
    }
    vector<int> path;
    while (right != -1) {
      path.push_back(right);
      right = parent[right];
    }
    int P = path.size();
    if (P % 2 == 0)
      return {path[P / 2], path[P / 2 - 1]};
    return {path[P / 2]};
  }
};
