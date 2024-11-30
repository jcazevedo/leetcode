// 2097. Valid Arrangement of Pairs
// https://leetcode.com/problems/valid-arrangement-of-pairs/

#include <algorithm>
#include <deque>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 private:
  void dfs(int u, unordered_map<int, deque<int>>& graph, vector<int>& path) {
    while (!graph[u].empty()) {
      int v = graph[u].front();
      graph[u].pop_front();
      dfs(v, graph, path);
    }
    path.push_back(u);
  }

 public:
  vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
    unordered_map<int, deque<int>> graph;
    unordered_map<int, int> inDegree, outDegree;
    for (const vector<int>& pair : pairs) {
      graph[pair[0]].push_back(pair[1]);
      outDegree[pair[0]]++;
      inDegree[pair[1]]++;
    }
    int start = -1;
    for (const pair<int, int> kv : outDegree) {
      if (kv.second == inDegree[kv.first] + 1) {
        start = kv.first;
        break;
      }
    }
    if (start == -1) { start = pairs[0][0]; }
    vector<int> path;
    dfs(start, graph, path);
    reverse(begin(path), end(path));
    vector<vector<int>> ans;
    for (int i = 1; i < (int)path.size(); ++i) { ans.push_back({path[i - 1], path[i]}); }
    return ans;
  }
};
