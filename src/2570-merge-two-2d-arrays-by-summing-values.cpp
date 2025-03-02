// 2570. Merge Two 2D Arrays by Summing Values
// https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/

#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
    map<int, int> values;
    for (vector<int>& v : nums1) { values[v[0]] += v[1]; }
    for (vector<int>& v : nums2) { values[v[0]] += v[1]; }
    vector<vector<int>> ans;
    for (map<int, int>::iterator itr = values.begin(); itr != values.end(); ++itr) {
      ans.push_back({itr->first, itr->second});
    }
    return ans;
  }
};
