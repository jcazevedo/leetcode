#include <vector>

using namespace std;

class Solution {
public:
  int search(vector<int>& nums, int target) {
    int N = nums.size();
    int lo = 0, hi = N;
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if (nums[mid] == target)
        return mid;
      if (nums[mid] < target)
        lo = mid + 1;
      else
        hi = mid;
    }
    return -1;
  }
};
