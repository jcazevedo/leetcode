#include <vector>

using namespace std;

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int idx = 0, cnt = 1, N = nums.size();
    for (int i = 1; i < N; ++i) {
      cnt += (nums[i] == nums[idx] ? 1 : -1);
      if (cnt == 0) {
        idx = i;
        cnt = 1;
      }
    }
    return nums[idx];
  }
};
