// 1512. Number of Good Pairs
// https://leetcode.com/problems/number-of-good-pairs/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int numIdenticalPairs(vector<int>& nums) {
    int N = nums.size();
    if (N <= 1)
      return 0;
    int ans = 0;
    unordered_map<int, int> counts;
    counts[nums[N - 1]]++;
    for (int i = N - 2; i >= 0; --i) {
      ans += counts[nums[i]];
      counts[nums[i]]++;
    }
    return ans;
  }
};
