// 2203. Minimum Weighted Subgraph With the Required Paths
// https://leetcode.com/problems/minimum-weighted-subgraph-with-the-required-paths/

#include <limits>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

#define INF (numeric_limits<long long>::max() / 3)

class Solution {
 private:
  vector<long long> dijkstra(const vector<vector<tuple<int, int>>>& graph, int n, int source) {
    vector<long long> distance(n, INF);
    priority_queue<tuple<long long, int>, vector<tuple<long long, int>>, greater<tuple<long long, int>>> pq;
    distance[source] = 0;
    pq.push({0, source});
    while (!pq.empty()) {
      long long currDistance;
      int currNode;
      tie(currDistance, currNode) = pq.top();
      pq.pop();
      if (currDistance > distance[currNode]) { continue; }
      for (const tuple<int, int>& next : graph[currNode]) {
        int nextNode = get<0>(next);
        long long nextDistance = currDistance + get<1>(next);
        if (nextDistance < distance[nextNode]) {
          distance[nextNode] = nextDistance;
          pq.push({nextDistance, nextNode});
        }
      }
    }
    return distance;
  }

 public:
  long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
    vector<vector<tuple<int, int>>> graph(n, vector<tuple<int, int>>());
    vector<vector<tuple<int, int>>> reverseGraph(n, vector<tuple<int, int>>());
    for (const vector<int>& edge : edges) {
      graph[edge[0]].push_back({edge[1], edge[2]});
      reverseGraph[edge[1]].push_back({edge[0], edge[2]});
    }
    vector<long long> dist1 = dijkstra(graph, n, src1);
    vector<long long> dist2 = dijkstra(graph, n, src2);
    vector<long long> distDest = dijkstra(reverseGraph, n, dest);
    long long ans = INF;
    for (int m = 0; m < n; ++m) {
      if (dist1[m] >= INF || dist2[m] >= INF || distDest[m] >= INF) { continue; }
      long long total = dist1[m] + dist2[m] + distDest[m];
      if (total < ans) { ans = total; }
    }
    return ans >= INF ? -1 : ans;
  }
};
