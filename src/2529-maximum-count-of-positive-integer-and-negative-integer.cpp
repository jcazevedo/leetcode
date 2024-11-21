// 2529. Maximum Count of Positive Integer and Negative Integer
// https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int maximumCount(vector<int>& nums) {
    int pos = 0, neg = 0;
    for (const int& num : nums) {
      if (num < 0) {
        ++neg;
      } else if (num > 0) {
        ++pos;
      }
    }
    return max(pos, neg);
  }
};
