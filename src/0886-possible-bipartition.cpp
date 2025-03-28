// 886. Possible Bipartition
// https://leetcode.com/problems/possible-bipartition/

#include <queue>
#include <vector>

using namespace std;

class Solution {
 private:
  bool bfs(int i, vector<int>& colors, vector<vector<int>>& graph) {
    colors[i] = 1;
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      int nextColor = 1 - colors[curr];
      for (int next : graph[curr]) {
        if (colors[next] == -1) {
          colors[next] = nextColor;
          q.push(next);
        } else if (colors[next] != nextColor) {
          return false;
        }
      }
    }
    return true;
  }

 public:
  bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
    vector<int> colors(N + 1, -1);
    vector<vector<int>> graph(N + 1, vector<int>());
    for (vector<int> edge : dislikes) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }
    for (int i = 1; i <= N; ++i) {
      if (colors[i] != -1) { continue; }
      if (!bfs(i, colors, graph)) { return false; }
    }
    return true;
  }
};
