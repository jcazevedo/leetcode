// 1786. Number of Restricted Paths From First to Last Node
// https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/

#include <limits>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

#define MOD 1000000007

class Solution {
 public:
  int countRestrictedPaths(int n, vector<vector<int>>& edges) {
    vector<vector<tuple<int, int>>> graph(n + 1, vector<tuple<int, int>>());
    for (const vector<int>& edge : edges) {
      graph[edge[0]].push_back({edge[1], edge[2]});
      graph[edge[1]].push_back({edge[0], edge[2]});
    }
    vector<long long> distance(n + 1, numeric_limits<long long>::max());
    priority_queue<tuple<long long, int>, vector<tuple<long long, int>>, greater<tuple<long long, int>>> pq;
    distance[n] = 0;
    pq.push({0, n});
    vector<int> order;
    while (!pq.empty()) {
      long long currDistance;
      int currNode;
      tie(currDistance, currNode) = pq.top();
      pq.pop();
      if (currDistance > distance[currNode]) { continue; }
      order.push_back(currNode);
      for (const tuple<int, int>& next : graph[currNode]) {
        int nextNode = get<0>(next);
        long long nextDistance = currDistance + get<1>(next);
        if (nextDistance < distance[nextNode]) {
          distance[nextNode] = nextDistance;
          pq.push({nextDistance, nextNode});
        }
      }
    }
    vector<long long> ways(n + 1, 0);
    ways[n] = 1;
    for (int u : order) {
      if (u == n) { continue; }
      long long total = 0;
      for (const tuple<int, int>& next : graph[u]) {
        int v = get<0>(next);
        if (distance[v] < distance[u]) { total = (total + ways[v]) % MOD; }
      }
      ways[u] = total;
    }
    return static_cast<int>(ways[1]);
  }
};
