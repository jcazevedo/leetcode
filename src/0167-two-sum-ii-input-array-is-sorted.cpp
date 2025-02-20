// 167. Two Sum II - Input Array Is Sorted
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int n = numbers.size();
    for (int i = 0; i < n; ++i) {
      int rem = target - numbers[i];
      int lo = i + 1;
      int hi = n;
      while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (numbers[mid] == rem) { return {i + 1, mid + 1}; }
        if (numbers[mid] < rem) {
          lo = mid + 1;
        } else {
          hi = mid;
        }
      }
    }
    return {};
  }
};
