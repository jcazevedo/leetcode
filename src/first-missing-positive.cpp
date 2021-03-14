#include <vector>

using namespace std;

class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
    int N = nums.size();
    int j = 0;
    for (int i = 0; i < N; i++) {
      if (nums[i] <= 0) {
        swap(nums[j++], nums[i]);
      }
    }
    int rem = N - j;
    for (int i = j; i < N; i++) {
      int t = nums[i] < 0 ? -nums[i] - 1 : nums[i] - 1;
      if (t >= 0 && t < rem && nums[t + j] > 0)
        nums[t + j] = -nums[t + j];
    }
    for (int i = j; i < N; i++) {
      if (nums[i] > 0)
        return i - j + 1;
    }
    return rem + 1;
  }
};
