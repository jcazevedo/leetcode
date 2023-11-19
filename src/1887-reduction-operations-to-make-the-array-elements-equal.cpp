// 1887. Reduction Operations to Make the Array Elements Equal
// https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int reductionOperations(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int N = nums.size(), ans = 0;
    for (int i = N - 2; i >= 0; --i)
      if (nums[i] != nums[i + 1])
        ans += N - i - 1;
    return ans;
  }
};
