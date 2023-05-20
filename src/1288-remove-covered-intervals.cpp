// 1288. Remove Covered Intervals
// https://leetcode.com/problems/remove-covered-intervals/

#include <vector>

using namespace std;

class Solution {
private:
  bool is_covered(const vector<int>& i1, const vector<int>& i2) { return i1[0] >= i2[0] && i1[1] <= i2[1]; }

public:
  int removeCoveredIntervals(vector<vector<int>>& intervals) {
    int N = intervals.size(), ans = intervals.size();
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (i == j)
          continue;
        if (is_covered(intervals[i], intervals[j])) {
          --ans;
          break;
        }
      }
    }
    return ans;
  }
};
