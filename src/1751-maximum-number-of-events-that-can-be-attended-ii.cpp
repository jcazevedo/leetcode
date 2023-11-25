// 1751. Maximum Number of Events That Can Be Attended II
// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 private:
  int binarySearch(const vector<vector<int>>& events, int endTime) {
    int lo = 0, hi = events.size();
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if (events[mid][0] <= endTime) {
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }
    return lo;
  }

  int dfs(int curr,
          const vector<vector<int>>& events,
          vector<vector<int>>& cache,
          int k) {
    if (curr >= (int)events.size() || k == 0) { return 0; }
    if (cache[curr][k] == -1) {
      int next = binarySearch(events, events[curr][1]);
      cache[curr][k] = max(dfs(curr + 1, events, cache, k),
                           events[curr][2] + dfs(next, events, cache, k - 1));
    }
    return cache[curr][k];
  }

 public:
  int maxValue(vector<vector<int>>& events, int k) {
    sort(events.begin(), events.end());
    vector<vector<int>> cache(events.size(), vector<int>(k + 1, -1));
    return dfs(0, events, cache, k);
  }
};
