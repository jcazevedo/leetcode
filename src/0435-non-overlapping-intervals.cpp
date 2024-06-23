// 435. Non-overlapping Intervals
// https://leetcode.com/problems/non-overlapping-intervals/

#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
 public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    vector<pair<int, int>> p_intervals;
    for (vector<int> interval : intervals) p_intervals.emplace_back(interval[1], interval[0]);
    sort(p_intervals.begin(), p_intervals.end());
    int ans = 0;
    int prev_end = INT_MIN;
    for (pair<int, int> interval : p_intervals) {
      if (interval.second >= prev_end) {
        prev_end = interval.first;
      } else {
        ans++;
      }
    }
    return ans;
  }
};
