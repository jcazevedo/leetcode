#include <vector>

using namespace std;

class Solution {
public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int N = nums.size();
    int l = 0;
    int product = 1;
    int ans = 0;
    for (int r = 0; r < N; ++r) {
      product *= nums[r];
      while (l <= r && product >= k) {
        product /= nums[l];
        l++;
      }
      if (l <= r)
        ans += (r - l) + 1;
    }
    return ans;
  }
};
