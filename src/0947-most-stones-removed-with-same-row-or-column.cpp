// 947. Most Stones Removed with Same Row or Column
// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

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
  int removeStones(vector<vector<int>>& stones) {
    int N = stones.size(), components = N;
    UnionFind uf(N);
    for (int i = 0; i < N; ++i) {
      for (int j = i + 1; j < N; ++j) {
        if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
          if (uf.findSet(i) != uf.findSet(j)) {
            --components;
            uf.unionSet(i, j);
          }
        }
      }
    }
    return N - components;
  }
};
