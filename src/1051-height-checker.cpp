// 1051. Height Checker
// https://leetcode.com/problems/height-checker/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int heightChecker(vector<int>& heights) {
    int n = heights.size();
    vector<int> toSort(n, 0);
    for (int i = 0; i < n; ++i) { toSort[i] = heights[i]; }
    sort(toSort.begin(), toSort.end());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (toSort[i] != heights[i]) { ++ans; }
    }
    return ans;
  }
};
