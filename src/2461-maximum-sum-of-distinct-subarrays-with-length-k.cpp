// 2461. Maximum Sum of Distinct Subarrays With Length K
// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/

#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  long long maximumSubarraySum(vector<int>& nums, int k) {
    int N = nums.size();
    unordered_map<int, int> currValues;
    unordered_set<int> repeated;
    long long currSum = 0L;
    long long ans = 0L;
    for (int i = 0; i < k; ++i) {
      currSum += nums[i];
      ++currValues[nums[i]];
      if (currValues[nums[i]] > 1) { repeated.insert(nums[i]); }
    }
    if (repeated.empty()) { ans = currSum; }
    for (int i = 1; i + k <= N; ++i) {
      currSum -= nums[i - 1];
      --currValues[nums[i - 1]];
      if (currValues[nums[i - 1]] == 1) { repeated.erase(nums[i - 1]); }
      currSum += nums[i + k - 1];
      ++currValues[nums[i + k - 1]];
      if (currValues[nums[i + k - 1]] > 1) { repeated.insert(nums[i + k - 1]); }
      if (repeated.empty()) { ans = max(ans, currSum); }
    }
    return ans;
  }
};
