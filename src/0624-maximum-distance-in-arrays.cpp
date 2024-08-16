// 624. Maximum Distance in Arrays
// https://leetcode.com/problems/maximum-distance-in-arrays/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxDistance(vector<vector<int>>& arrays) {
    int N = arrays.size();
    vector<vector<int>> mins(N);
    vector<vector<int>> maxs(N);
    for (int a = 0; a < N; ++a) {
      mins[a] = {arrays[a][0], a};
      maxs[a] = {arrays[a][arrays[a].size() - 1], a};
    }
    sort(mins.begin(), mins.end());
    sort(maxs.begin(), maxs.end());
    if (mins[0][1] != maxs[N - 1][1]) { return maxs[N - 1][0] - mins[0][0]; }
    return max(maxs[N - 1][0] - mins[1][0], maxs[N - 2][0] - mins[0][0]);
  }
};
