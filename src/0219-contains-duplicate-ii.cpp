// 219. Contains Duplicate II
// https://leetcode.com/problems/contains-duplicate-ii/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int N = nums.size();
    unordered_map<int, int> counts;
    for (int i = 0; i < N; ++i) {
      if (counts[nums[i]] > 0)
        return true;
      counts[nums[i]]++;
      if (i - k >= 0)
        counts[nums[i - k]]--;
    }
    return false;
  }
};
