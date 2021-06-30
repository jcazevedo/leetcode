#include <vector>

using namespace std;

class Solution {
private:
  bool good(int divisor, int threshold, const vector<int> &nums) {
    int sum = 0;
    for (int num : nums) {
      sum += ((num + divisor - 1) / divisor);
    }
    return sum <= threshold;
  }

public:
  int smallestDivisor(vector<int> &nums, int threshold) {
    int lo = 1, hi = 1000000;
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if (good(mid, threshold, nums))
        hi = mid;
      else
        lo = mid + 1;
    }
    return lo;
  }
};
