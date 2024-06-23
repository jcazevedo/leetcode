// 1235. Maximum Profit in Job Scheduling
// https://leetcode.com/problems/maximum-profit-in-job-scheduling/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 private:
  int maxProfit(int idx, const vector<vector<int>>& jobs, vector<int>& cache) {
    if (idx >= (int)jobs.size()) return 0;
    if (cache[idx] != -1) return cache[idx];

    int with = jobs[idx][2];
    vector<int> tmp = {jobs[idx][1], 0, 0};
    int nextIdx = lower_bound(jobs.begin(), jobs.end(), tmp) - jobs.begin();
    with += maxProfit(nextIdx, jobs, cache);
    int without = maxProfit(idx + 1, jobs, cache);
    int best = max(with, without);
    cache[idx] = best;

    return best;
  }

 public:
  int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    int N = startTime.size();
    vector<vector<int>> jobs;
    for (int i = 0; i < N; ++i) jobs.push_back({startTime[i], endTime[i], profit[i]});
    sort(jobs.begin(), jobs.end());

    vector<int> cache(N, -1);
    return maxProfit(0, jobs, cache);
  }
};
