// 3524. Find X Value of Array I
// https://leetcode.com/problems/find-x-value-of-array-i/

#include <vector>

using namespace std;

class Solution {
 public:
  vector<long long> resultArray(vector<int>& nums, int k) {
    vector<long long> ans(k);
    vector<long long> ending(k);
    for (int num : nums) {
      vector<long long> next(k);
      int rem = num % k;
      for (int prev = 0; prev < k; ++prev) { next[prev * rem % k] += ending[prev]; }
      ++next[rem];
      for (int curr = 0; curr < k; ++curr) { ans[curr] += next[curr]; }
      ending.swap(next);
    }
    return ans;
  }
};
