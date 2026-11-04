// 3505. Minimum Operations to Make Elements Within K Subarrays Equal
// https://leetcode.com/problems/minimum-operations-to-make-elements-within-k-subarrays-equal/

#include <algorithm>
#include <functional>
#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  long long minOperations(vector<int>& nums, int x, int k) {
    int n = nums.size();
    multiset<int> low, high;
    long long sumLow = 0, sumHigh = 0;
    function<void()> rebalance = [&]() {
      while (low.size() > high.size() + 1) {
        multiset<int>::iterator it = prev(low.end());
        sumLow -= *it;
        sumHigh += *it;
        high.insert(*it);
        low.erase(it);
      }
      while (low.size() < high.size()) {
        multiset<int>::iterator it = high.begin();
        sumHigh -= *it;
        sumLow += *it;
        low.insert(*it);
        high.erase(it);
      }
    };
    vector<long long> cost(n - x + 1);
    for (int i = 0; i < n; ++i) {
      if (i >= x) {
        multiset<int>::iterator it = low.find(nums[i - x]);
        if (it != low.end()) {
          sumLow -= *it;
          low.erase(it);
        } else {
          it = high.find(nums[i - x]);
          sumHigh -= *it;
          high.erase(it);
        }
        rebalance();
      }
      if (low.empty() || nums[i] <= *low.rbegin()) {
        low.insert(nums[i]);
        sumLow += nums[i];
      } else {
        high.insert(nums[i]);
        sumHigh += nums[i];
      }
      rebalance();
      if (i >= x - 1) {
        long long median = *low.rbegin();
        cost[i - x + 1] = median * low.size() - sumLow + sumHigh - median * high.size();
      }
    }
    vector<long long> previous(n + 1, 0), current(n + 1);
    for (int j = 1; j <= k; ++j) {
      fill(current.begin(), current.end(), -1);
      for (int i = n - j * x; i >= 0; --i) {
        if (current[i + 1] == -1) {
          current[i] = cost[i] + previous[i + x];
        } else {
          current[i] = min(current[i + 1], cost[i] + previous[i + x]);
        }
      }
      previous.swap(current);
    }
    return previous[0];
  }
};
