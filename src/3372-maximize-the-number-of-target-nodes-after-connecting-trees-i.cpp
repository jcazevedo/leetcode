// 3372. Maximize the Number of Target Nodes After Connecting Trees I
// https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/

#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 private:
  int getTargetNodes(int start, vector<vector<int>>& tree, int k) {
    if (k < 0) { return 0; }
    int n = tree.size();
    vector<bool> visited(n, false);
    queue<pair<int, int>> q;
    visited[start] = true;
    q.push({start, 0});
    while (!q.empty()) {
      pair<int, int> curr = q.front();
      q.pop();
      int u = curr.first;
      int d = curr.second;
      if (d == k) { continue; }
      for (int v : tree[u]) {
        if (visited[v]) { continue; }
        visited[v] = true;
        q.push({v, d + 1});
      }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (visited[i]) { ++ans; }
    }
    return ans;
  }

 public:
  vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
    int n = edges1.size() + 1, m = edges2.size() + 1;
    vector<vector<int>> tree1(n, vector<int>()), tree2(m, vector<int>());
    for (const vector<int>& edge : edges1) {
      tree1[edge[0]].push_back(edge[1]);
      tree1[edge[1]].push_back(edge[0]);
    }
    for (const vector<int>& edge : edges2) {
      tree2[edge[0]].push_back(edge[1]);
      tree2[edge[1]].push_back(edge[0]);
    }
    int best = 0;
    for (int i = 0; i < m; ++i) { best = max(best, getTargetNodes(i, tree2, k - 1)); }
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) { ans[i] = getTargetNodes(i, tree1, k) + best; }
    return ans;
  }
};
