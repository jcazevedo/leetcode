// 976. Largest Perimeter Triangle
// https://leetcode.com/problems/largest-perimeter-triangle/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
  bool is_triangle(int a, int b, int c) {
    return a + b > c && a + c > b && b + c > a;
  }

public:
  int largestPerimeter(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    for (int i = (int)nums.size() - 1; i >= 2; --i)
      if (is_triangle(nums[i], nums[i - 1], nums[i - 2]))
        return nums[i] + nums[i - 1] + nums[i - 2];

    return 0;
  }
};
