// 1630. Arithmetic Subarrays
// https://leetcode.com/problems/arithmetic-subarrays/

#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
    int M = l.size();
    vector<bool> ans(M, false);
    for (int m = 0; m < M; ++m) {
      int minV = nums[l[m]];
      int maxV = nums[l[m]];
      int len = r[m] - l[m] + 1;
      unordered_set<int> values;
      values.insert(nums[l[m]]);
      for (int i = l[m] + 1; i <= r[m]; ++i) {
        minV = min(minV, nums[i]);
        maxV = max(maxV, nums[i]);
        values.insert(nums[i]);
      }
      if ((maxV - minV) % (len - 1) != 0)
        ans[m] = false;
      else {
        ans[m] = true;
        int diff = (maxV - minV) / (len - 1);
        if (diff != 0)
          for (int v = minV; v <= maxV; v += diff)
            if (values.find(v) == values.end()) {
              ans[m] = false;
              break;
            }
      }
    }
    return ans;
  }
};
