// 2873. Maximum Value of an Ordered Triplet I
// https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  long long maximumTripletValue(vector<int>& nums) {
    long long ans = 0L;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        for (int k = j + 1; k < n; ++k) { ans = max(ans, ((long long)nums[i] - nums[j]) * nums[k]); }
      }
    }
    return ans;
  }
};
