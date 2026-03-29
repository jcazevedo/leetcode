// 3886. Sum of Sortable Integers
// https://leetcode.com/problems/sum-of-sortable-integers/

#include <algorithm>
#include <cmath>
#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  int sortableIntegers(vector<int>& nums) {
    int n = nums.size(), ans = 0;
    for (int k = 1; k <= sqrt(n); ++k) {
      if (n % k == 0) {
        set<int> ks = {k, n / k};
        for (int l : ks) {
          int prev = 0, c = n / l;
          bool good = true;
          for (int i = 0; i < c && good; ++i) {
            int breaks = 0, next_prev = prev;
            for (int j = i * l; j < (i + 1) * l; ++j) {
              if (nums[j] < prev) {
                good = false;
                break;
              }
              next_prev = max(next_prev, nums[j]);
              if (nums[j] > nums[(j + 1) % l + i * l]) {
                ++breaks;
                if (breaks > 1) {
                  good = false;
                  break;
                }
              }
            }
            prev = next_prev;
          }
          if (good) { ans += l; }
        }
      }
    }
    return ans;
  }
};
