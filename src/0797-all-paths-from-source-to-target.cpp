// 797. All Paths From Source to Target
// https://leetcode.com/problems/all-paths-from-source-to-target/

#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 private:
  void go(vector<vector<int>>& graph,
          int curr,
          int end,
          vector<vector<int>>& paths,
          vector<int>& curr_path,
          unordered_set<int>& visited) {
    if (curr == end)
      paths.push_back(curr_path);
    else {
      for (int next : graph[curr]) {
        if (visited.count(next) > 0) continue;
        curr_path.push_back(next);
        visited.insert(next);
        go(graph, next, end, paths, curr_path, visited);
        visited.erase(next);
        curr_path.pop_back();
      }
    }
  }

 public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    int N = graph.size();
    vector<vector<int>> paths;
    vector<int> curr_path = {0};
    unordered_set<int> visited;
    go(graph, 0, N - 1, paths, curr_path, visited);
    return paths;
  }
};
