// 1921. Eliminate Maximum Number of Monsters
// https://leetcode.com/problems/eliminate-maximum-number-of-monsters/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    int N = dist.size();
    vector<int> turnsToReachCity(N, 0);
    for (int i = 0; i < N; ++i) turnsToReachCity[i] = (dist[i] + speed[i] - 1) / speed[i];
    sort(turnsToReachCity.begin(), turnsToReachCity.end());
    int ans = 0;
    for (int i = 0; i < N; ++i) {
      if (turnsToReachCity[i] <= ans) break;
      ++ans;
    }
    return ans;
  }
};
