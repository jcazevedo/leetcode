// 1722. Minimize Hamming Distance After Swap Operations
// https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/

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
      if (rank[x] > rank[y]) {
        p[y] = x;
      } else {
        p[x] = y;
        if (rank[x] == rank[y]) rank[y]++;
      }
    }
  }
};

class Solution {
 public:
  int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
    int n = source.size();
    UnionFind uf(n);
    for (const vector<int>& swap : allowedSwaps) { uf.unionSet(swap[0], swap[1]); }
    unordered_map<int, unordered_map<int, int>> counts;
    for (int i = 0; i < n; ++i) { ++counts[uf.findSet(i)][source[i]]; }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      unordered_map<int, int>& group = counts[uf.findSet(i)];
      unordered_map<int, int>::iterator it = group.find(target[i]);
      if (it != group.end() && it->second > 0) {
        --it->second;
      } else {
        ++ans;
      }
    }
    return ans;
  }
};
