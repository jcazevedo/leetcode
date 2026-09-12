// 3414. Maximum Score of Non-overlapping Intervals
// https://leetcode.com/problems/maximum-score-of-non-overlapping-intervals/

#include <algorithm>
#include <array>
#include <vector>

using namespace std;

struct Interval {
  int start;
  int end;
  int weight;
  int index;
};

struct Result {
  long long score = 0;
  vector<int> indices;
};

class Solution {
 private:
  bool better(const Result& a, const Result& b) {
    return a.score != b.score ? a.score > b.score : a.indices < b.indices;
  }

 public:
  vector<int> maximumWeight(vector<vector<int>>& intervals) {
    vector<Interval> sorted;
    for (int i = 0; i < (int)intervals.size(); ++i) {
      sorted.push_back({intervals[i][0], intervals[i][1], intervals[i][2], i});
    }
    sort(sorted.begin(), sorted.end(), [](const Interval& a, const Interval& b) { return a.start < b.start; });
    vector<int> starts;
    for (const Interval& interval : sorted) { starts.push_back(interval.start); }
    int n = sorted.size();
    vector<int> next(n);
    for (int i = 0; i < n; ++i) { next[i] = upper_bound(starts.begin(), starts.end(), sorted[i].end) - starts.begin(); }
    vector<array<Result, 5>> dp(n + 1);
    for (int i = n - 1; i >= 0; --i) {
      for (int remaining = 1; remaining <= 4; ++remaining) {
        Result take = dp[next[i]][remaining - 1];
        take.score += sorted[i].weight;
        take.indices.insert(lower_bound(take.indices.begin(), take.indices.end(), sorted[i].index), sorted[i].index);
        dp[i][remaining] = better(take, dp[i + 1][remaining]) ? take : dp[i + 1][remaining];
      }
    }
    return dp[0][4].indices;
  }
};
