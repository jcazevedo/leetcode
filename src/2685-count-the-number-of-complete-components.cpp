// 2685. Count the Number of Complete Components
// https://leetcode.com/problems/count-the-number-of-complete-components/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 private:
  void dfs(int u, int c, const vector<vector<int>>& graph, vector<int>& component) {
    component[u] = c;
    for (int v : graph[u]) {
      if (component[v] != -1) { continue; }
      dfs(v, c, graph, component);
    }
  }

 public:
  int countCompleteComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>> graph(n, vector<int>());
    for (const vector<int>& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }
    vector<int> component(n, -1);
    int ans = 0, components = 0;
    for (int i = 0; i < n; ++i) {
      if (component[i] != -1) { continue; }
      dfs(i, components, graph, component);
      bool good = true;
      for (int j = 0; j < n && good; ++j) {
        if (component[j] != components) { continue; }
        for (int k = 0; k < n && good; ++k) {
          if (j == k || component[k] != components) { continue; }
          if (find(graph[j].begin(), graph[j].end(), k) == graph[j].end()) { good = false; }
        }
      }
      if (good) { ++ans; }
      ++components;
    }
    return ans;
  }
};
