// 1192. Critical Connections in a Network
// https://leetcode.com/problems/critical-connections-in-a-network/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 private:
  void tarjanAux(int u,
                 int parent,
                 vector<int>& disc,
                 vector<int>& low,
                 int& time,
                 const vector<vector<int>>& graph,
                 vector<vector<int>>& bridges) {
    ++time;
    disc[u] = low[u] = time;
    for (int v : graph[u]) {
      if (v == parent) { continue; }
      if (disc[v] != 0) {
        low[u] = min(low[u], disc[v]);
      } else {
        tarjanAux(v, u, disc, low, time, graph, bridges);
        low[u] = min(low[u], low[v]);
        if (low[v] > disc[u]) { bridges.push_back({u, v}); }
      }
    }
  }

  vector<vector<int>> tarjan(const vector<vector<int>>& graph) {
    int V = graph.size();
    vector<int> disc(V, 0);
    vector<int> low(V, 0);
    int time = 0;
    vector<vector<int>> ans;
    for (int i = 0; i < V; ++i) {
      if (disc[i] == 0) { tarjanAux(i, -1, disc, low, time, graph, ans); }
    }
    return ans;
  }

 public:
  vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<vector<int>> graph(n, vector<int>());
    int C = connections.size();
    for (int c = 0; c < C; ++c) {
      graph[connections[c][0]].push_back(connections[c][1]);
      graph[connections[c][1]].push_back(connections[c][0]);
    }
    return tarjan(graph);
  }
};
