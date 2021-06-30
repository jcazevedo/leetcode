#include <vector>

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int N = nums.size();
    int curr = nums[0];
    int best = nums[0];
    for (int i = 1; i < N; ++i) {
      curr = nums[i] + curr > nums[i] ? nums[i] + curr : nums[i];
      best = max(best, curr);
    }
    return best;
  }
};
