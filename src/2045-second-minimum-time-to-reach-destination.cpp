// 2045. Second Minimum Time to Reach Destination
// https://leetcode.com/problems/second-minimum-time-to-reach-destination/

#include <limits>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
 public:
  int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
    vector<vector<int>> graph(n + 1, vector<int>());
    for (const vector<int>& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }
    vector<int> minDist(n + 1, numeric_limits<int>::max());
    vector<int> secondMinDist(n + 1, numeric_limits<int>::max());
    vector<int> nVisited(n + 1, 0);
    priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<tuple<int, int>>> pq;
    pq.push({0, 1});
    minDist[1] = 0;
    while (!pq.empty()) {
      int distance, u;
      tie(distance, u) = pq.top();
      pq.pop();
      ++nVisited[u];
      if (nVisited[u] == 2 && u == n) { return distance; }
      if ((distance / change) % 2 == 0) {
        distance = distance + time;
      } else {
        distance = change * (distance / change + 1) + time;
      }
      for (int v : graph[u]) {
        if (nVisited[v] == 2) { continue; }
        if (minDist[v] > distance) {
          secondMinDist[v] = minDist[v];
          minDist[v] = distance;
          pq.push({distance, v});
        } else if (secondMinDist[v] > distance && minDist[v] != distance) {
          secondMinDist[v] = distance;
          pq.push({distance, v});
        }
      }
    }
    return -1;
  }
};
