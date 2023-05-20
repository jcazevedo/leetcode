// 189. Rotate Array
// https://leetcode.com/problems/rotate-array/

#include <vector>

using namespace std;

class Solution {
private:
  void reverse(vector<int>& nums, int left, int right) {
    while (left < right) {
      int tmp = nums[left];
      nums[left] = nums[right];
      nums[right] = tmp;
      left++;
      right--;
    }
  }

public:
  void rotate(vector<int>& nums, int k) {
    int L = nums.size();
    if (L <= 1)
      return;
    k %= L;
    reverse(nums, 0, L - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, L - 1);
  }
};
