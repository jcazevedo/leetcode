// 2573. Find the String with LCP
// https://leetcode.com/problems/find-the-string-with-lcp/

#include <string>
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
  string findTheString(vector<vector<int>>& lcp) {
    int n = lcp.size();
    UnionFind uf(n);
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (lcp[i][j] > 0) { uf.unionSet(i, j); }
      }
    }
    string word(n, 0);
    char ch = 'a';
    for (int i = 0; i < n; i++) {
      if (word[i] != 0) { continue; }
      if (ch > 'z') { return ""; }
      for (int j = i; j < n; j++) {
        if (uf.findSet(j) == uf.findSet(i)) { word[j] = ch; }
      }
      ch++;
    }
    for (int i = n - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        int expected;
        if (word[i] != word[j]) {
          expected = 0;
        } else {
          expected = (i + 1 < n && j + 1 < n) ? lcp[i + 1][j + 1] + 1 : 1;
        }
        if (lcp[i][j] != expected) { return ""; }
      }
    }
    return word;
  }
};
