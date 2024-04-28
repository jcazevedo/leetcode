// 834. Sum of Distances in Tree
// https://leetcode.com/problems/sum-of-distances-in-tree/

#include <vector>

using namespace std;

class Solution {
 private:
  void dfs1(int node,
            int parent,
            int currDepth,
            const vector<vector<int>>& tree,
            vector<int>& nodes,
            vector<int>& depths) {
    int n = 1;
    for (const int& neighbor : tree[node]) {
      if (neighbor == parent) continue;
      dfs1(neighbor, node, currDepth + 1, tree, nodes, depths);
      n += nodes[neighbor];
    }
    nodes[node] = n;
    depths[node] = currDepth;
  }

  void dfs2(int node,
            int parent,
            int currDistance,
            const vector<vector<int>>& tree,
            const vector<int>& nodes,
            vector<int>& ans) {
    ans[node] = currDistance;
    for (const int& neighbor : tree[node]) {
      if (neighbor == parent) continue;
      dfs2(neighbor, node,
           currDistance - nodes[neighbor] + (tree.size() - nodes[neighbor]),
           tree, nodes, ans);
    }
  }

 public:
  vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    vector<int> nodes(n, 0);
    vector<int> depths(n, 0);
    vector<vector<int>> tree(n, vector<int>());
    for (const vector<int>& edge : edges) {
      tree[edge[0]].push_back(edge[1]);
      tree[edge[1]].push_back(edge[0]);
    }
    dfs1(0, -1, 0, tree, nodes, depths);
    int startingDistance = 0;
    for (int v : depths) startingDistance += v;
    vector<int> ans(n);
    dfs2(0, -1, startingDistance, tree, nodes, ans);
    return ans;
  }
};
