// 743. Network Delay Time
// https://leetcode.com/problems/network-delay-time/

#include <algorithm>
#include <limits>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
 public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<tuple<int, int>>> graph(n + 1, vector<tuple<int, int>>());
    for (const vector<int>& edge : times) { graph[edge[0]].push_back({edge[1], edge[2]}); }
    vector<int> distance(n + 1, numeric_limits<int>::max());
    priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<tuple<int, int>>> pq;
    pq.push({0, k});
    distance[k] = 0;
    int ans = 0;
    int remaining = n;
    while (!pq.empty()) {
      int currNode, currDistance;
      tie(currDistance, currNode) = pq.top();
      pq.pop();
      if (distance[currNode] < currDistance) { continue; }
      ans = max(ans, currDistance);
      --remaining;
      for (const tuple<int, int>& next : graph[currNode]) {
        int nextNode = get<0>(next);
        int nextDistance = get<1>(next) + currDistance;
        if (distance[nextNode] > nextDistance) {
          distance[nextNode] = nextDistance;
          pq.push({nextDistance, nextNode});
        }
      }
    }
    if (remaining != 0) { return -1; }
    return ans;
  }
};
