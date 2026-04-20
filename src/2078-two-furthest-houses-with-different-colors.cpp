// 2078. Two Furthest Houses With Different Colors
// https://leetcode.com/problems/two-furthest-houses-with-different-colors/

#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxDistance(vector<int>& colors) {
    unordered_map<int, int> minD, maxD;
    int n = colors.size();
    for (int i = 0; i < n; ++i) {
      if (minD.find(colors[i]) == minD.end()) { minD[colors[i]] = i; }
      maxD[colors[i]] = i;
    }
    int ans = 0;
    for (int i = 0; i <= 100; ++i) {
      if (minD.find(i) == minD.end()) { continue; }
      for (int j = i + 1; j <= 100; ++j) {
        if (minD.find(j) == minD.end()) { continue; }
        ans = max(ans, abs(maxD[j] - minD[i]));
        ans = max(ans, abs(maxD[i] - minD[j]));
      }
    }
    return ans;
  }
};
