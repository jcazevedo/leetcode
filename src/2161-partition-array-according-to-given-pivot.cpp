// 2161. Partition Array According to Given Pivot
// https://leetcode.com/problems/partition-array-according-to-given-pivot/

#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> pivotArray(vector<int>& nums, int pivot) {
    int n = nums.size();
    vector<int> l, r;
    for (int i = 0; i < n; ++i) {
      if (nums[i] < pivot) { l.push_back(nums[i]); }
      if (nums[i] > pivot) { r.push_back(nums[i]); }
    }
    vector<int> ans(n);
    int ll = l.size();
    int rl = r.size();
    int m = n - ll - rl;
    int li = 0;
    int ri = 0;
    for (int i = 0; i < n; ++i) {
      if (li < ll) {
        ans[i] = l[li++];
      } else if (m > 0) {
        ans[i] = pivot;
        --m;
      } else {
        ans[i] = r[ri++];
      }
    }
    return ans;
  }
};
