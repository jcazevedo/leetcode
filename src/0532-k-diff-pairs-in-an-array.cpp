// 532. K-diff Pairs in an Array
// https://leetcode.com/problems/k-diff-pairs-in-an-array/

#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int findPairs(vector<int>& nums, int k) {
    unordered_set<int> visited, ans;
    for (int num : nums) {
      if (visited.count(num - k) != 0)
        ans.insert(num);
      if (visited.count(num + k) != 0)
        ans.insert(num + k);
      visited.insert(num);
    }
    return ans.size();
  }
};
