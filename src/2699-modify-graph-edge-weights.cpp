// 2699. Modify Graph Edge Weights
// https://leetcode.com/problems/modify-graph-edge-weights/

#include <queue>
#include <utility>
#include <vector>

using namespace std;

#define INF (2 * 1e9)

class Solution {
 private:
  int dijkstra(const vector<vector<pair<int, int>>>& graph, int source, int destination) {
    int N = graph.size();
    vector<int> dist(N, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[source] = 0;
    pq.emplace(0, source);
    while (!pq.empty()) {
      pair<int, int> curr = pq.top();
      int currDist = curr.first;
      int currNode = curr.second;
      pq.pop();
      if (currDist > dist[currNode]) { continue; }
      for (vector<pair<int, int>>::const_iterator it = graph[currNode].begin(); it != graph[currNode].end(); ++it) {
        int next = it->first;
        int weight = it->second;
        if (currDist + weight < dist[next]) {
          dist[next] = currDist + weight;
          pq.emplace(dist[next], next);
        }
      }
    }
    return dist[destination];
  }

 public:
  vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
    vector<vector<pair<int, int>>> graph(n);
    for (const vector<int>& edge : edges) {
      if (edge[2] != -1) {
        graph[edge[0]].emplace_back(edge[1], edge[2]);
        graph[edge[1]].emplace_back(edge[0], edge[2]);
      }
    }
    int currDist = dijkstra(graph, source, destination);
    if (currDist < target) { return vector<vector<int>>(); }
    bool matches = currDist == target;
    for (vector<int>& edge : edges) {
      if (edge[2] != -1) { continue; }
      edge[2] = matches ? INF : 1;
      graph[edge[0]].emplace_back(edge[1], edge[2]);
      graph[edge[1]].emplace_back(edge[0], edge[2]);
      if (!matches) {
        int newDist = dijkstra(graph, source, destination);
        if (newDist <= target) {
          matches = true;
          edge[2] += target - newDist;
        }
      }
    }
    if (matches) { return edges; }
    return vector<vector<int>>();
  }
};
