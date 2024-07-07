// 684. Redundant Connection
// https://leetcode.com/problems/redundant-connection/

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
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    UnionFind uf(n + 1);
    for (const vector<int>& edge : edges) {
      if (uf.findSet(edge[0]) == uf.findSet(edge[1])) return edge;
      uf.unionSet(edge[0], edge[1]);
    }
    return {-1, -1};
  }
};
