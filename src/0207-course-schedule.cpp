// 207. Course Schedule
// https://leetcode.com/problems/course-schedule/

#include <vector>

using namespace std;

class Solution {
 private:
  vector<vector<int>> graph;
  vector<bool> visited;
  vector<bool> stack;

  bool dfs(int u) {
    if (!visited[u]) {
      visited[u] = true;
      stack[u] = true;
      for (int v : graph[u]) {
        if ((!visited[v] && dfs(v)) || stack[v]) return true;
      }
    }
    stack[u] = false;
    return false;
  }

 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    graph.assign(numCourses, vector<int>());
    for (vector<int> edge : prerequisites) {
      graph[edge[1]].push_back(edge[0]);
    }
    visited.assign(numCourses, false);
    stack.assign(numCourses, false);
    for (int i = 0; i < numCourses; ++i) {
      if (dfs(i)) return false;
    }
    return true;
  }
};
