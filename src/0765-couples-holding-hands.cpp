// 765. Couples Holding Hands
// https://leetcode.com/problems/couples-holding-hands/

#include <vector>

using namespace std;

class Solution {
public:
  int minSwapsCouples(vector<int>& row) {
    int N = row.size() / 2;
    vector<int> uf = vector<int>(N, -1);
    for (int i = 0; i < N; i++)
      uf[i] = i;
    int tot = 0;
    for (int i = 0; i < N; i++) {
      int g1 = findSet(uf, row[i * 2] / 2);
      int g2 = findSet(uf, row[i * 2 + 1] / 2);
      if (g1 != g2) {
        tot++;
        uf[g1] = g2;
      }
    }
    return tot;
  }

  int findSet(vector<int>& uf, int v) {
    while (v != uf[v])
      v = uf[v];
    return v;
  }
};
