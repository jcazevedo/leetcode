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
 public:
  int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
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
    for (int i = 1; i <= n; ++i) {
      if (alice.findSet(i) != alice.findSet(1)) { return -1; }
      if (bob.findSet(i) != bob.findSet(1)) { return -1; }
    }
    return E - used;
  }
};
