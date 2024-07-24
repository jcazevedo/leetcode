// 2191. Sort the Jumbled Numbers
// https://leetcode.com/problems/sort-the-jumbled-numbers/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 private:
  int mappedValue(int num, const vector<int>& mapping) {
    if (num == 0) { return mapping[0]; }
    int ans = 0;
    int p = 1;
    while (num) {
      int dig = mapping[num % 10];
      ans += p * dig;
      p *= 10;
      num /= 10;
    }
    return ans;
  }

 public:
  vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
    vector<vector<int>> toSort;
    int N = nums.size();
    for (int i = 0; i < N; ++i) { toSort.push_back({mappedValue(nums[i], mapping), i}); }
    sort(toSort.begin(), toSort.end());
    vector<int> ans;
    for (const vector<int>& v : toSort) { ans.push_back(nums[v[1]]); }
    return ans;
  }
};
