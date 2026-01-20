// 3314. Construct the Minimum Bitwise Array I
// https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/

#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> minBitwiseArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
      if (nums[i] % 2 == 0) {
        ans[i] = -1;
      } else {
        for (int n = 0; n < nums[i]; ++n) {
          if ((n | (n + 1)) == nums[i]) {
            ans[i] = n;
            break;
          }
        }
      }
    }
    return ans;
  }
};
