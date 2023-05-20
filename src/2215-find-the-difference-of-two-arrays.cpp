// 2215. Find the Difference of Two Arrays
// https://leetcode.com/problems/find-the-difference-of-two-arrays/

#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    set<int> set1, set2;
    for (int num : nums1)
      set1.insert(num);
    for (int num : nums2)
      set2.insert(num);
    vector<vector<int>> ans = {vector<int>(), vector<int>()};
    for (int n1 : set1)
      if (set2.find(n1) == set2.end())
        ans[0].push_back(n1);
    for (int n2 : set2)
      if (set1.find(n2) == set1.end())
        ans[1].push_back(n2);
    return ans;
  }
};
