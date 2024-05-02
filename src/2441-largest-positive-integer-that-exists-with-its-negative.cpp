// 2441. Largest Positive Integer That Exists With Its Negative
// https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/

#include <cmath>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int findMaxK(vector<int>& nums) {
    unordered_set<int> visited;
    int ans = -1;
    for (int num : nums) {
      if (visited.find(-num) != visited.end()) ans = max(ans, abs(num));
      visited.insert(num);
    }
    return ans;
  }
};
