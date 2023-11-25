// 1557. Minimum Number of Vertices to Reach All Nodes
// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

#include <set>
#include <vector>

using namespace std;

class Solution {
private:
  void dfs(int curr, int start, const vector<vector<int>>& graph,
           vector<bool>& visited, set<int>& minSet) {
    if (visited[curr]) {
      minSet.erase(curr);
      minSet.insert(start);
      return;
    }

    visited[curr] = true;
    for (int next : graph[curr])
      dfs(next, start, graph, visited, minSet);
  }

public:
  vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    vector<bool> visited = vector<bool>(n, false);
    vector<vector<int>> graph = vector<vector<int>>(n, vector<int>());
    for (const vector<int>& edge : edges)
      graph[edge[0]].push_back(edge[1]);

    set<int> minSet;
    for (int i = 0; i < n; ++i)
      if (!visited[i]) {
        minSet.insert(i);
        dfs(i, i, graph, visited, minSet);
      }

    vector<int> ans;
    for (int i : minSet)
      ans.push_back(i);

    return ans;
  }
};
