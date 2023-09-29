// 896. Monotonic Array
// https://leetcode.com/problems/monotonic-array/

#include <vector>

using namespace std;

class Solution {
private:
  int sign(int v) {
    if (v > 0)
      return 1;
    else if (v < 0)
      return -1;
    return 0;
  }

public:
  bool isMonotonic(vector<int>& nums) {
    int N = nums.size();
    if (N <= 1)
      return true;
    int diff = 0;
    for (int i = 1; i < N; ++i) {
      int nextDiff = sign(nums[i] - nums[i - 1]);
      if (diff != 0 && nextDiff != 0 && nextDiff != diff)
        return false;
      if (nextDiff != 0)
        diff = nextDiff;
    }
    return true;
  }
};
