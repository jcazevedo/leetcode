// 3425. Longest Special Path
// https://leetcode.com/problems/longest-special-path/

#include <vector>

using namespace std;

class Solution {
 private:
  void go(int u,
          int parent,
          int start,
          vector<vector<vector<int>>>& tree,
          vector<int>& nums,
          vector<int>& visited,
          vector<int>& length,
          vector<int>& pathIdx,
          vector<int>& next,
          vector<int>& ans) {
    int nodes = pathIdx[u] - pathIdx[start] + 1;
    int len = length[u] - length[start];
    if (len > ans[0]) {
      ans = {len, nodes};
    } else if (len == ans[0] && nodes < ans[1]) {
      ans = {len, nodes};
    }
    for (const vector<int>& edge : tree[u]) {
      if (edge[0] == parent) { continue; }
      int nextStart;
      if (visited[nums[edge[0]]] != -1 && pathIdx[visited[nums[edge[0]]]] >= pathIdx[start]) {
        int prev = visited[nums[edge[0]]];
        if (next[prev] == -1) {
          nextStart = edge[0];
        } else {
          nextStart = next[prev];
        }
      } else {
        nextStart = start;
      }
      int prevV = visited[nums[edge[0]]];
      int prevNext = next[u];
      length[edge[0]] = length[u] + edge[1];
      visited[nums[edge[0]]] = edge[0];
      next[u] = edge[0];
      pathIdx[edge[0]] = pathIdx[u] + 1;
      go(edge[0], u, nextStart, tree, nums, visited, length, pathIdx, next, ans);
      visited[nums[edge[0]]] = prevV;
      next[u] = prevNext;
    }
  }

 public:
  vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
    int N = nums.size();
    vector<vector<vector<int>>> tree(N, vector<vector<int>>());
    for (const vector<int>& edge : edges) {
      tree[edge[0]].push_back({edge[1], edge[2]});
      tree[edge[1]].push_back({edge[0], edge[2]});
    }
    vector<int> ans = {0, 1};
    vector<int> visited(50001, -1);
    vector<int> length(N, -1);
    vector<int> pathIdx(N, -1);
    vector<int> next(N, -1);
    length[0] = 0;
    pathIdx[0] = 0;
    visited[nums[0]] = 0;
    go(0, -1, 0, tree, nums, visited, length, pathIdx, next, ans);
    return ans;
  }
};
