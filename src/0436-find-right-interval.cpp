// 436. Find Right Interval
// https://leetcode.com/problems/find-right-interval/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findRightInterval(vector<vector<int>>& intervals) {
    int N = intervals.size();
    for (int i = 0; i < N; ++i)
      intervals[i].push_back(i);
    sort(intervals.begin(), intervals.end());
    vector<int> ans = vector<int>(N, -1);
    for (int i = 0; i < N; ++i) {
      int lo = i, hi = N;
      while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (intervals[mid][0] < intervals[i][1])
          lo = mid + 1;
        else
          hi = mid;
      }
      ans[intervals[i][2]] = lo == N ? -1 : intervals[lo][2];
    }
    return ans;
  }
};
