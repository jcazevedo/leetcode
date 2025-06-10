// 1061. Lexicographically Smallest Equivalent String
// https://leetcode.com/problems/lexicographically-smallest-equivalent-string/

#include <string>
#include <vector>

using namespace std;

class UnionFind {
 private:
  vector<int> p, rank;

 public:
  UnionFind(int N) {
    p.assign(N, 0);
    for (int i = 0; i < N; i++) { p[i] = i; }
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }

  bool connectedSet(int i, int j) { return findSet(i) == findSet(j); }

  void unionSet(int i, int j) {
    if (!connectedSet(i, j)) {
      int x = findSet(i);
      int y = findSet(j);
      p[y] = min(x, y);
      p[x] = min(x, y);
    }
  }
};

class Solution {
 public:
  string smallestEquivalentString(string s1, string s2, string baseStr) {
    int l = 'z' - 'a' + 1;
    UnionFind uf(l);
    int n = s1.size();
    for (int i = 0; i < n; ++i) { uf.unionSet(s1[i] - 'a', s2[i] - 'a'); }
    string ans = "";
    for (char ch : baseStr) { ans += (uf.findSet(ch - 'a') + 'a'); }
    return ans;
  }
};
