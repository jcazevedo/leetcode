// 2642. Design Graph With Shortest Path Calculator
// https://leetcode.com/problems/design-graph-with-shortest-path-calculator/

#include <queue>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace std;

class Graph {
 private:
  int N;
  vector<vector<vector<int>>> graph;

 public:
  Graph(int n, vector<vector<int>>& edges) {
    N = n;
    graph = vector<vector<vector<int>>>(n, vector<vector<int>>());
    for (vector<int> edge : edges) graph[edge[0]].push_back(edge);
  }

  void addEdge(vector<int> edge) { graph[edge[0]].push_back(edge); }

  int shortestPath(int node1, int node2) {
    unordered_map<int, int> distances;
    for (int i = 0; i < N; ++i) distances[i] = -1;

    priority_queue<tuple<int, int>, vector<tuple<int, int>>,
                   std::greater<tuple<int, int>>>
        pq;
    distances[node1] = 0;
    pq.push({0, node1});

    while (!pq.empty()) {
      int dist, u;
      tie(dist, u) = pq.top();
      pq.pop();

      if (u == node2) return dist;

      for (vector<int> edge : graph[u]) {
        int v = edge[1];
        int newDist = dist + edge[2];

        if (distances[v] == -1 || newDist < distances[v]) {
          distances[v] = newDist;
          pq.push({newDist, v});
        }
      }
    }

    return -1;
  }
};
