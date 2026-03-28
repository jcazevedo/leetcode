// 1632. Rank Transform of a Matrix
// https://leetcode.com/problems/rank-transform-of-a-matrix/

#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
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
  vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
    int M = matrix.size();
    int N = matrix[0].size();
    vector<vector<int>> ans(M, vector<int>(N, 0));
    map<int, vector<pair<int, int>>> grouped;
    for (int i = 0; i < M; ++i)
      for (int j = 0; j < N; ++j) grouped[matrix[i][j]].push_back({i, j});
    vector<int> rank(M + N, 0);
    for (map<int, vector<pair<int, int>>>::const_iterator entry = grouped.begin(); entry != grouped.end(); ++entry) {
      UnionFind uf(M + N);
      vector<pair<int, int>> coords = entry->second;
      for (vector<pair<int, int>>::const_iterator coord = coords.begin(); coord != coords.end(); ++coord)
        uf.unionSet(coord->first, coord->second + M);
      unordered_map<int, set<int>> groups;
      for (vector<pair<int, int>>::const_iterator coord = coords.begin(); coord != coords.end(); ++coord) {
        groups[uf.findSet(coord->first)].insert(coord->first);
        groups[uf.findSet(coord->first)].insert(coord->second + M);
        groups[uf.findSet(coord->second + M)].insert(coord->first);
        groups[uf.findSet(coord->second + M)].insert(coord->second + M);
      }
      for (unordered_map<int, set<int>>::const_iterator grp = groups.begin(); grp != groups.end(); ++grp) {
        int max_rank = 0;
        for (int i : grp->second) max_rank = max(max_rank, rank[i]);
        for (int i : grp->second) rank[i] = max_rank + 1;
      }
      for (vector<pair<int, int>>::const_iterator coord = coords.begin(); coord != coords.end(); ++coord)
        ans[coord->first][coord->second] = rank[coord->first];
    }
    return ans;
  }
};
