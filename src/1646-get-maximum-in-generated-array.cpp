// 1646. Get Maximum in Generated Array
// https://leetcode.com/problems/get-maximum-in-generated-array/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int getMaximumGenerated(int n) {
    if (n == 0) return 0;
    vector<int> nums(n + 1, 0);
    nums[0] = 0;
    nums[1] = 1;
    int ans = 1;
    for (int i = 2; i <= n; ++i) {
      if (i % 2 == 0) {
        nums[i] = nums[i / 2];
      } else {
        nums[i] = nums[(i - 1) / 2] + nums[(i - 1) / 2 + 1];
      }
      ans = max(ans, nums[i]);
    }
    return ans;
  }
};
