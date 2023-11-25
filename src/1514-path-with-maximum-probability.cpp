// 1514. Path with Maximum Probability
// https://leetcode.com/problems/path-with-maximum-probability/

#include <queue>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  double maxProbability(int n,
                        vector<vector<int>>& edges,
                        vector<double>& succProb,
                        int start,
                        int end) {
    vector<vector<tuple<int, double>>> graph =
        vector<vector<tuple<int, double>>>(n, vector<tuple<int, double>>());
    int E = edges.size();
    for (int i = 0; i < E; ++i) {
      int u = edges[i][0];
      int v = edges[i][1];
      double p = succProb[i];
      graph[u].push_back({v, p});
      graph[v].push_back({u, p});
    }
    priority_queue<tuple<double, int>> pq;
    unordered_map<int, double> visited;
    pq.push({1.0, start});
    visited[start] = 1.0;
    while (!pq.empty()) {
      double currProb;
      int u;
      tie(currProb, u) = pq.top();
      pq.pop();
      if (u == end) return currProb;
      for (int i = 0; i < (int)graph[u].size(); ++i) {
        int v = get<0>(graph[u][i]);
        double nextProb = get<1>(graph[u][i]) * currProb;
        if (visited.find(v) == visited.end() || visited[v] < nextProb) {
          visited[v] = nextProb;
          pq.push({nextProb, v});
        }
      }
    }
    return 0.0;
  }
};
