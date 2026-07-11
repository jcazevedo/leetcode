// 2685. Count the Number of Complete Components
// https://leetcode.com/problems/count-the-number-of-complete-components/

#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  int countCompleteComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>> graph(n);
    for (const vector<int>& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }
    vector<bool> visited(n, false);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (visited[i]) { continue; }
      int vertexCount = 0;
      long long degreeSum = 0;
      stack<int> s;
      s.push(i);
      visited[i] = true;
      while (!s.empty()) {
        const int u = s.top();
        s.pop();
        ++vertexCount;
        degreeSum += graph[u].size();
        for (int v : graph[u]) {
          if (visited[v]) { continue; }
          visited[v] = true;
          s.push(v);
        }
      }
      if (degreeSum == 1LL * vertexCount * (vertexCount - 1)) { ++ans; }
    }
    return ans;
  }
};
