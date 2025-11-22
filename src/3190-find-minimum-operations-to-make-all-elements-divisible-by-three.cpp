// 3190. Find Minimum Operations to Make All Elements Divisible by Three
// https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumOperations(vector<int>& nums) {
    int ans = 0;
    for (int num : nums) {
      int rem = num % 3;
      ans += min(rem, 3 - rem);
    }
    return ans;
  }
};
