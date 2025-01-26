// 2127. Maximum Employees to Be Invited to a Meeting
// https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/

#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 private:
  int bfs(int start, vector<vector<int>>& graph, unordered_set<int>& visited) {
    queue<pair<int, int>> q;
    q.push({start, 0});
    int ans = 0;
    while (!q.empty()) {
      pair<int, int> curr = q.front();
      q.pop();
      int node = curr.first;
      int dist = curr.second;
      for (int next : graph[node]) {
        if (visited.count(next)) { continue; }
        visited.insert(next);
        q.push({next, dist + 1});
        ans = max(ans, dist + 1);
      }
    }
    return ans;
  }

 public:
  int maximumInvitations(vector<int>& favorite) {
    int N = favorite.size();
    vector<vector<int>> graph(N);
    for (int i = 0; i < N; ++i) { graph[favorite[i]].push_back(i); }
    int cycle = 0, composite = 0;
    vector<bool> visited(N, false);
    for (int i = 0; i < N; ++i) {
      if (visited[i]) { continue; }
      unordered_map<int, int> visitedNodes;
      int curr = i;
      int dist = 0;
      while (!visited[curr]) {
        visited[curr] = true;
        visitedNodes[curr] = dist++;
        int next = favorite[curr];
        if (visitedNodes.count(next)) {
          int len = dist - visitedNodes[next];
          cycle = max(cycle, len);
          if (len == 2) {
            unordered_set<int> visitedSoFar = {curr, next};
            composite += 2 + bfs(next, graph, visitedSoFar) + bfs(curr, graph, visitedSoFar);
          }
        }
        curr = next;
      }
    }
    return max(cycle, composite);
  }
};
