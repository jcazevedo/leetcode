// 1579. Remove Max Number of Edges to Keep Graph Fully Traversable
// https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/

#include <algorithm>
#include <vector>

using namespace std;

class UnionFind {
 private:
  vector<int> p, rank;

 public:
  UnionFind(int N) {
    rank.assign(N, 0);
    p.assign(N, 0);
    for (int i = 0; i < N; i++) p[i] = i;
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }

  bool connectedSet(int i, int j) { return findSet(i) == findSet(j); }

  void unionSet(int i, int j) {
    if (!connectedSet(i, j)) {
      int x = findSet(i);
      int y = findSet(j);
      if (rank[x] > rank[y])
        p[y] = x;
      else {
        p[x] = y;
        if (rank[x] == rank[y]) rank[y]++;
      }
    }
  }
};

class Solution {
 private:
  void dfs(int u, int t, vector<bool>& visited, const vector<vector<vector<int>>>& graph) {
    for (const vector<int>& next : graph[u]) {
      if ((next[0] == t || next[0] == 3) && !visited[next[1]]) {
        visited[next[1]] = true;
        dfs(next[1], t, visited, graph);
      }
    }
  }

 public:
  int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
    vector<vector<vector<int>>> graph(n + 1, vector<vector<int>>());
    for (const vector<int>& edge : edges) {
      graph[edge[1]].push_back({edge[0], edge[2]});
      graph[edge[2]].push_back({edge[0], edge[1]});
    }
    vector<bool> visited(n + 1, false);
    visited[1] = true;
    dfs(1, 1, visited, graph);
    for (int i = 1; i <= n; ++i) {
      if (!visited[i]) { return -1; }
      visited[i] = false;
    }
    visited[1] = true;
    dfs(1, 2, visited, graph);
    for (int i = 1; i <= n; ++i) {
      if (!visited[i]) { return -1; }
    }
    UnionFind alice(n + 1);
    UnionFind bob(n + 1);
    int used = 0;
    sort(edges.begin(), edges.end());
    int E = edges.size();
    for (int i = E - 1; i >= 0; --i) {
      if (edges[i][0] == 3) {
        if (alice.findSet(edges[i][1]) != alice.findSet(edges[i][2]) ||
            bob.findSet(edges[i][1]) != bob.findSet(edges[i][2])) {
          ++used;
          alice.unionSet(edges[i][1], edges[i][2]);
          bob.unionSet(edges[i][1], edges[i][2]);
        }
      } else if (edges[i][0] == 2) {
        if (bob.findSet(edges[i][1]) != bob.findSet(edges[i][2])) {
          ++used;
          bob.unionSet(edges[i][1], edges[i][2]);
        }
      } else if (edges[i][0] == 1) {
        if (alice.findSet(edges[i][1]) != alice.findSet(edges[i][2])) {
          ++used;
          alice.unionSet(edges[i][1], edges[i][2]);
        }
      }
    }
    return E - used;
  }
};
