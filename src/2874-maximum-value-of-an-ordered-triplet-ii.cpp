// 2874. Maximum Value of an Ordered Triplet II
// https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/

#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class Solution {
 private:
  void inc(map<long long, int>& m, int v) { ++m[v]; }

  void dec(map<long long, int>& m, int v) {
    --m[v];
    if (m[v] == 0) { m.erase(v); }
  }

 public:
  long long maximumTripletValue(vector<int>& nums) {
    map<long long, int> left, right;
    int n = nums.size();
    inc(left, nums[0]);
    for (int i = 1; i < n; ++i) { inc(right, nums[i]); }
    long long ans = 0L;
    for (int j = 1; j < n - 1; ++j) {
      dec(right, nums[j]);
      ans = max(ans, (left.rbegin()->first - nums[j]) * (right.rbegin()->first));
      inc(left, nums[j]);
    }
    return ans;
  }
};
