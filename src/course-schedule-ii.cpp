#include <stack>
#include <vector>

using namespace std;

class Solution {
private:
  int N;
  vector<vector<int>> graph;
  vector<bool> visited;
  vector<bool> in_stack;
  stack<int> s;

  bool has_cycle_dfs(int u) {
    if (!visited[u]) {
      visited[u] = true;
      in_stack[u] = true;
      for (int v : graph[u]) {
        if ((!visited[v] && has_cycle_dfs(v)) || in_stack[v])
          return true;
      }
    }
    in_stack[u] = false;
    return false;
  }

  bool has_cycle() {
    visited.assign(N, false);
    in_stack.assign(N, false);
    for (int i = 0; i < N; ++i) {
      if (has_cycle_dfs(i))
        return true;
    }
    return false;
  }

  void topological_sort_dfs(int u) {
    visited[u] = true;
    for (int v : graph[u]) {
      if (!visited[v])
        topological_sort_dfs(v);
    }
    s.push(u);
  }

  vector<int> topological_sort() {
    visited.assign(N, false);
    for (int i = 0; i < N; ++i) {
      if (!visited[i])
        topological_sort_dfs(i);
    }
    vector<int> res;
    while (!s.empty()) {
      res.push_back(s.top());
      s.pop();
    }
    return res;
  }

public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    N = numCourses;
    graph.assign(N, vector<int>());
    for (vector<int> req : prerequisites) {
      graph[req[1]].push_back(req[0]);
    }
    if (has_cycle())
      return {};
    return topological_sort();
  }
};
