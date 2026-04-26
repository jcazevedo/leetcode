// 3357. Minimize the Maximum Adjacent Element Difference
// https://leetcode.com/problems/minimize-the-maximum-adjacent-element-difference/

#include <algorithm>
#include <limits>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 private:
  bool feasible(const vector<int>& nums, int d) {
    int n = nums.size();
    vector<pair<int, int>> tight, loose;
    int i = 0;
    while (i < n) {
      if (nums[i] != -1) {
        ++i;
        continue;
      }
      int j = i;
      while (j < n && nums[j] == -1) { ++j; }
      bool hasL = (i > 0);
      bool hasR = (j < n);
      int runLen = j - i;
      if (hasL || hasR) {
        int a = numeric_limits<int>::min(), b = numeric_limits<int>::max();
        if (hasL) {
          a = max(a, nums[i - 1] - d);
          b = min(b, nums[i - 1] + d);
        }
        if (hasR) {
          a = max(a, nums[j] - d);
          b = min(b, nums[j] + d);
        }
        if (runLen == 1) {
          tight.push_back({a, b});
          loose.push_back({a, b});
        } else {
          tight.push_back({a, b});
          if (hasL) { loose.push_back({nums[i - 1] - d, nums[i - 1] + d}); }
          if (hasR) { loose.push_back({nums[j] - d, nums[j] + d}); }
        }
      }
      i = j;
    }
    return canCoverTwo(tight, numeric_limits<int>::max()) || canCoverTwo(loose, d);
  }

  bool canCoverTwo(vector<pair<int, int>> ivs, int maxDiff) {
    if (ivs.empty()) { return true; }
    for (size_t k = 0; k < ivs.size(); ++k) {
      if (ivs[k].first > ivs[k].second) { return false; }
    }
    sort(ivs.begin(), ivs.end(), [](const pair<int, int>& p, const pair<int, int>& q) { return p.second < q.second; });
    long long x = ivs[0].second;
    long long yLo = numeric_limits<long long>::min(), yHi = numeric_limits<long long>::max();
    for (size_t k = 0; k < ivs.size(); ++k) {
      long long a = ivs[k].first;
      long long b = ivs[k].second;
      if (a <= x) { continue; }
      yLo = max(yLo, a);
      yHi = min(yHi, b);
    }
    if (yLo == numeric_limits<long long>::min()) { return true; }
    yLo = max(yLo, x - maxDiff);
    yHi = min(yHi, x + maxDiff);
    return yLo <= yHi;
  }

 public:
  int minDifference(vector<int>& nums) {
    int n = nums.size();
    int lo = 0, hi = 0;
    for (int v : nums) { hi = max(hi, v); }
    for (int i = 0; i + 1 < n; ++i) {
      if (nums[i] != -1 && nums[i + 1] != -1) { lo = max(lo, abs(nums[i] - nums[i + 1])); }
    }
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if (feasible(nums, mid)) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    return lo;
  }
};
