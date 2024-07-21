// 2392. Build a Matrix With Conditions
// https://leetcode.com/problems/build-a-matrix-with-conditions/

#include <queue>
#include <vector>

using namespace std;

class Solution {
 private:
  vector<int> topoSort(vector<vector<int>>& edges, int n) {
    vector<vector<int>> graph(n + 1);
    vector<int> inDegree(n + 1);
    vector<int> ans;
    for (const vector<int>& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      inDegree[edge[1]]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
      if (inDegree[i] == 0) { q.push(i); }
    }
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      ans.push_back(u);
      --n;
      for (int v : graph[u]) {
        --inDegree[v];
        if (inDegree[v] == 0) { q.push(v); }
      }
    }
    if (n != 0) return {};
    return ans;
  }

 public:
  vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
    vector<int> rows = topoSort(rowConditions, k);
    vector<int> columns = topoSort(colConditions, k);
    if (rows.empty() || columns.empty()) return {};
    vector<vector<int>> ans(k, vector<int>(k, 0));
    for (int i = 0; i < k; ++i) {
      for (int j = 0; j < k; ++j) {
        if (rows[i] == columns[j]) { ans[i][j] = rows[i]; }
      }
    }
    return ans;
  }
};
