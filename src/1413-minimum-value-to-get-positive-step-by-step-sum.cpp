// 1413. Minimum Value to Get Positive Step by Step Sum
// https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/

#include <vector>

using namespace std;

class Solution {
public:
  int minStartValue(vector<int>& nums) {
    int N = nums.size(), sum = 0, curr = 1;
    for (int i = 0; i < N; ++i) {
      sum += nums[i];
      curr = max(curr, (-sum) + 1);
    }
    return curr;
  }
};
