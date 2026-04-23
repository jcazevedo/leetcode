// 2615. Sum of Distances
// https://leetcode.com/problems/sum-of-distances/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<long long> distance(vector<int>& nums) {
    int n = nums.size();
    vector<long long> ans(n, 0L);
    unordered_map<int, long long> left, right, leftCnt, rightCnt;
    for (int i = 0; i < n; ++i) {
      right[nums[i]] += i;
      ++rightCnt[nums[i]];
    }
    for (int i = 0; i < n; ++i) {
      right[nums[i]] -= i;
      --rightCnt[nums[i]];
      ans[i] += right[nums[i]] - rightCnt[nums[i]] * i;
      ans[i] += leftCnt[nums[i]] * i - left[nums[i]];
      left[nums[i]] += i;
      ++leftCnt[nums[i]];
    }
    return ans;
  }
};
