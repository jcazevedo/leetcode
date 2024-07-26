// 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

#include <limits>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<vector<int>>> graph(n, vector<vector<int>>());
    for (const vector<int>& edge : edges) {
      graph[edge[0]].push_back({edge[1], edge[2]});
      graph[edge[1]].push_back({edge[0], edge[2]});
    }
    int ans = -1;
    int minCitiesReached = numeric_limits<int>::max();
    for (int i = 0; i < n; ++i) {
      unordered_set<int> visited;
      priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
      pq.push({0, i});
      int reached = 0;
      while (!pq.empty()) {
        vector<int> curr = pq.top();
        pq.pop();
        int dist = curr[0];
        int u = curr[1];
        if (visited.find(u) != visited.end()) { continue; }
        visited.insert(u);
        if (u != i && dist <= distanceThreshold) { ++reached; }
        for (const vector<int>& next : graph[u]) {
          int v = next[0];
          int weight = next[1];
          if (visited.find(v) == visited.end()) { pq.push({dist + weight, v}); }
        }
      }
      if (reached <= minCitiesReached) {
        minCitiesReached = reached;
        ans = i;
      }
    }
    return ans;
  }
};
