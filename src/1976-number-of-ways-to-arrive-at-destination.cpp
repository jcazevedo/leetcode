// 1976. Number of Ways to Arrive at Destination
// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

#include <limits>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

#define MOD 1000000007

class Solution {
 public:
  int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<tuple<int, long long>>> graph(n, vector<tuple<int, long long>>());
    for (const vector<int>& edge : roads) {
      graph[edge[0]].push_back({edge[1], edge[2]});
      graph[edge[1]].push_back({edge[0], edge[2]});
    }
    vector<long long> distance(n, numeric_limits<long long>::max());
    vector<long long> ways(n, 0L);
    priority_queue<tuple<long long, int>, vector<tuple<long long, int>>, greater<tuple<long long, int>>> pq;
    pq.push({0L, 0});
    distance[0] = 0L;
    ways[0] = 1L;
    while (!pq.empty()) {
      int u;
      long long dist;
      tie(dist, u) = pq.top();
      pq.pop();
      if (distance[u] < dist) { continue; }
      for (const tuple<int, long long>& next : graph[u]) {
        int v = get<0>(next);
        long long nextDist = get<1>(next) + dist;
        if (distance[v] > nextDist) {
          distance[v] = nextDist;
          ways[v] = ways[u];
          pq.push({nextDist, v});
        } else if (distance[v] == nextDist) {
          ways[v] = (ways[v] + ways[u]) % MOD;
        }
      }
    }
    return ways[n - 1];
  }
};
