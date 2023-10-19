// 2050. Parallel Courses III
// https://leetcode.com/problems/parallel-courses-iii/

#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
    vector<vector<int>> graph(n, vector<int>());
    vector<int> inDegree(n, 0);
    for (const vector<int>& edge : relations) {
      graph[edge[0] - 1].push_back(edge[1] - 1);
      inDegree[edge[1] - 1]++;
    }
    queue<int> q;
    vector<int> timeToFinish(n, 0);
    for (int u = 0; u < n; ++u) {
      if (inDegree[u] == 0) {
        q.push(u);
        timeToFinish[u] = time[u];
      }
    }
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : graph[u]) {
        timeToFinish[v] = max(timeToFinish[v], timeToFinish[u] + time[v]);
        inDegree[v]--;
        if (inDegree[v] == 0) {
          q.push(v);
        }
      }
    }
    int ans = 0;
    for (int u = 0; u < n; ++u) {
      ans = max(ans, timeToFinish[u]);
    }
    return ans;
  }
};
