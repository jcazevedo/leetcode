// 2497. Maximum Star Sum of a Graph
// https://leetcode.com/problems/maximum-star-sum-of-a-graph/

#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
    int n = vals.size();
    vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
    for (const vector<int>& edge : edges) {
      graph[edge[0]].push_back(make_pair(vals[edge[1]], edge[1]));
      graph[edge[1]].push_back(make_pair(vals[edge[0]], edge[0]));
    }
    for (int i = 0; i < n; ++i) {
      sort(graph[i].begin(), graph[i].end());
      reverse(graph[i].begin(), graph[i].end());
    }
    int ans = numeric_limits<int>::min();
    for (int i = 0; i < n; ++i) {
      int curr = vals[i];
      int m = graph[i].size();
      for (int j = 0; j < min(m, k) && graph[i][j].first > 0; ++j) { curr += graph[i][j].first; }
      ans = max(ans, curr);
    }
    return ans;
  }
};
