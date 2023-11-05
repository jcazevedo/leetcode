// 2924. Find Champion II
// https://leetcode.com/problems/find-champion-ii/

#include <vector>

using namespace std;

class Solution {
public:
  int findChampion(int n, vector<vector<int>>& edges) {
    vector<int> inDeg(n, 0);
    for (const vector<int>& edge : edges)
      inDeg[edge[1]]++;
    int ans = -1;
    for (int i = 0; i < n; ++i)
      if (inDeg[i] == 0) {
        if (ans != -1)
          return -1;
        ans = i;
      }
    return ans;
  }
};
