// 3011. Find if Array Can Be Sorted
// https://leetcode.com/problems/find-if-array-can-be-sorted/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 private:
  int bitsSet(int num) {
    int ans = 0;
    while (num) {
      if (num % 2) { ++ans; }
      num /= 2;
    }
    return ans;
  }

 public:
  bool canSortArray(vector<int>& nums) {
    int N = nums.size();
    for (int i = 0; i < N - 1; ++i) {
      for (int j = 0; j < N - i - 1; ++j) {
        if (nums[j] > nums[j + 1]) {
          if (bitsSet(nums[j]) != bitsSet(nums[j + 1])) { return false; }
          swap(nums[j], nums[j + 1]);
        }
      }
    }
    return true;
  }
};
