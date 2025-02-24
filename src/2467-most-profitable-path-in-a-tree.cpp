// 2467. Most Profitable Path in a Tree
// https://leetcode.com/problems/most-profitable-path-in-a-tree/

#include <algorithm>
#include <limits>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 private:
  void dfs(int curr, int prev, int bob, vector<vector<int>>& tree, vector<int>& leafs, vector<int>& parent) {
    int cnt = 0;
    for (int next : tree[curr]) {
      if (next == prev) { continue; }
      ++cnt;
      parent[next] = curr;
      dfs(next, curr, bob, tree, leafs, parent);
    }
    if (cnt == 0) { leafs.push_back(curr); }
  }

 public:
  int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
    int n = edges.size() + 1;
    vector<vector<int>> tree(n, vector<int>());
    for (const vector<int>& edge : edges) {
      tree[edge[0]].push_back(edge[1]);
      tree[edge[1]].push_back(edge[0]);
    }
    vector<int> leafs;
    vector<int> parent(n, -1);
    dfs(0, -1, bob, tree, leafs, parent);
    vector<int> bobPath;
    int node = bob;
    do {
      bobPath.push_back(node);
      node = parent[node];
    } while (node != -1);
    int b = bobPath.size();
    int ans = numeric_limits<int>::min();
    for (int leaf : leafs) {
      vector<bool> open(n, false);
      vector<int> currPath;
      int node = leaf;
      do {
        currPath.push_back(node);
        node = parent[node];
      } while (node != -1);
      reverse(begin(currPath), end(currPath));
      int l = currPath.size();
      int curr = 0;
      for (int i = 0; i < l; ++i) {
        if (i < b && currPath[i] == bobPath[i]) {
          open[currPath[i]] = true;
          curr += amount[currPath[i]] / 2;
        } else {
          if (!open[currPath[i]]) {
            open[currPath[i]] = true;
            curr += amount[currPath[i]];
          }
          if (i < b && !open[bobPath[i]]) { open[bobPath[i]] = true; }
        }
      }
      ans = max(ans, curr);
    }
    return ans;
  }
};
