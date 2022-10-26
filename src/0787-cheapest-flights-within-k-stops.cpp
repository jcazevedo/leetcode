// 787. Cheapest Flights Within K Stops
// https://leetcode.com/problems/cheapest-flights-within-k-stops/

#include <map>
#include <vector>

using namespace std;

class Solution {
 private:
  vector<vector<pair<int, int>>> graph;
  vector<bool> visited;
  int target;
  int max_steps;
  int best;

  void go(int u, int steps = 0, int cost = 0) {
    if (u == target && (best == -1 || best > cost)) best = cost;
    if (steps == max_steps + 1) return;
    for (pair<int, int> next : graph[u]) {
      int v = next.first;
      int c = next.second;
      if (visited[v] || (best != -1 && cost + c >= best)) continue;
      visited[v] = true;
      go(v, steps + 1, cost + c);
      visited[v] = false;
    }
  }

 public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    graph.assign(n, vector<pair<int, int>>());
    for (vector<int> edge : flights) graph[edge[0]].emplace_back(edge[1], edge[2]);
    visited.assign(n, false);
    visited[src] = true;
    target = dst;
    max_steps = K;
    best = -1;
    go(src);
    return best;
  }
};
