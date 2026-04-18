// 1928. Minimum Cost to Reach Destination in Time
// https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time/

#include <limits>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
 public:
  int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
    int n = passingFees.size();
    vector<vector<tuple<int, int>>> graph(n, vector<tuple<int, int>>());
    for (const vector<int>& edge : edges) {
      graph[edge[0]].push_back({edge[1], edge[2]});
      graph[edge[1]].push_back({edge[0], edge[2]});
    }
    vector<vector<int>> dist(n, vector<int>(maxTime + 1, numeric_limits<int>::max()));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    dist[0][0] = passingFees[0];
    pq.push({passingFees[0], 0, 0});
    while (!pq.empty()) {
      int currCost, currNode, currTime;
      tie(currCost, currNode, currTime) = pq.top();
      pq.pop();
      if (currCost > dist[currNode][currTime]) { continue; }
      if (currNode == n - 1) { return currCost; }
      for (const tuple<int, int>& next : graph[currNode]) {
        int nextNode = get<0>(next);
        int nextTime = currTime + get<1>(next);
        if (nextTime > maxTime) { continue; }
        int nextCost = currCost + passingFees[nextNode];
        if (nextCost < dist[nextNode][nextTime]) {
          dist[nextNode][nextTime] = nextCost;
          pq.push({nextCost, nextNode, nextTime});
        }
      }
    }
    return -1;
  }
};
