// 2054. Two Best Non-Overlapping Events
// https://leetcode.com/problems/two-best-non-overlapping-events/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxTwoEvents(vector<vector<int>>& events) {
    int N = events.size();
    sort(events.begin(), events.end());
    vector<int> maxValueFrom(N, -1);
    maxValueFrom[N - 1] = events[N - 1][2];
    for (int i = N - 2; i >= 0; --i) { maxValueFrom[i] = max(events[i][2], maxValueFrom[i + 1]); }
    int ans = -1;
    for (int i = 0; i < N; ++i) {
      int lo = i + 1;
      int hi = N - 1;
      while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (events[mid][0] > events[i][1]) {
          hi = mid;
        } else {
          lo = mid + 1;
        }
      }
      if (lo >= N || events[lo][0] <= events[i][1]) {
        ans = max(ans, events[i][2]);
      } else {
        ans = max(ans, events[i][2] + maxValueFrom[lo]);
      }
    }
    return ans;
  }
};
