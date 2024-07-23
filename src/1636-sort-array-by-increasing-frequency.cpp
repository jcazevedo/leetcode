// 1636. Sort Array by Increasing Frequency
// https://leetcode.com/problems/sort-array-by-increasing-frequency/

#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> frequencySort(vector<int>& nums) {
    unordered_map<int, int> freq;
    for (int num : nums) { ++freq[num]; }
    vector<vector<int>> toSort;
    for (unordered_map<int, int>::iterator itr = freq.begin(); itr != freq.end(); ++itr) {
      toSort.push_back({itr->second, -itr->first});
    }
    sort(toSort.begin(), toSort.end());
    vector<int> ans;
    for (const vector<int>& elem : toSort) {
      for (int i = 0; i < elem[0]; ++i) { ans.push_back(-elem[1]); }
    }
    return ans;
  }
};
