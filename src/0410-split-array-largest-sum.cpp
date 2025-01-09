// 410. Split Array Largest Sum
// https://leetcode.com/problems/split-array-largest-sum/description/

#include <vector>

using namespace std;

class Solution {
 private:
  bool good(const vector<int>& nums, int k, int atMost) {
    int N = nums.size();
    int curr = 0, i = 0;
    while (i < N) {
      while (i < N && curr + nums[i] <= atMost && N - (i + 1) >= (k - 1)) {
        curr += nums[i];
        ++i;
      }
      --k;
      if (k == 0 && i < N) { return false; }
      curr = 0;
    }
    return true;
  }

 public:
  int splitArray(vector<int>& nums, int k) {
    int lo = 0, hi = 1000000000;
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if (good(nums, k, mid)) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    return lo;
  }
};
