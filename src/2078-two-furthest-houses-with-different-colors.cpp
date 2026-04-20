// 2078. Two Furthest Houses With Different Colors
// https://leetcode.com/problems/two-furthest-houses-with-different-colors/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxDistance(vector<int>& colors) {
    int n = colors.size(), i = n - 1, j = 0;
    while (colors[i] == colors[0]) { --i; }
    while (colors[j] == colors[n - 1]) { ++j; }
    return max(i, n - 1 - j);
  }
};
