// 456. 132 Pattern
// https://leetcode.com/problems/132-pattern/

#include <algorithm>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  bool find132pattern(vector<int>& nums) {
    int N = nums.size();
    if (N < 3)
      return false;

    multiset<int> rightVs;
    int minV = nums[0];
    for (int i = 2; i < N; ++i)
      rightVs.insert(nums[i]);

    for (int i = 1; i < N - 1; ++i) {
      if (nums[i] > minV) {
        multiset<int>::iterator leftItr = rightVs.upper_bound(minV);
        if (leftItr != rightVs.end() && *leftItr < nums[i])
          return true;
      }

      minV = min(minV, nums[i]);
      rightVs.erase(rightVs.find(nums[i + 1]));
    }

    return false;
  }
};
