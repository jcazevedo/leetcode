// 3532. Path Existence Queries in a Graph I
// https://leetcode.com/problems/path-existence-queries-in-a-graph-i/

#include <vector>

using namespace std;

class UnionFind {
 private:
  vector<int> p, rank;

 public:
  UnionFind(int N) {
    rank.assign(N, 0);
    p.assign(N, 0);
    for (int i = 0; i < N; i++) { p[i] = i; }
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }

  bool connectedSet(int i, int j) { return findSet(i) == findSet(j); }

  void unionSet(int i, int j) {
    if (!connectedSet(i, j)) {
      int x = findSet(i);
      int y = findSet(j);
      if (rank[x] > rank[y]) {
        p[y] = x;
      } else {
        p[x] = y;
        if (rank[x] == rank[y]) { ++rank[y]; }
      }
    }
  }
};

class Solution {
 public:
  vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
    UnionFind uf(n);
    for (int i = 1; i < n; ++i) {
      if (nums[i] - nums[i - 1] <= maxDiff) { uf.unionSet(i - 1, i); }
    }
    vector<bool> ans(queries.size());
    for (int i = 0; i < (int)queries.size(); ++i) { ans[i] = uf.connectedSet(queries[i][0], queries[i][1]); }
    return ans;
  }
};
