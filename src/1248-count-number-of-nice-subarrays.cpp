// 1248. Count Number of Nice Subarrays
// https://leetcode.com/problems/count-number-of-nice-subarrays/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int numberOfSubarrays(vector<int>& nums, int k) {
    int curr = 0;
    int ans = 0;
    unordered_map<int, int> sum;
    sum[curr] = 1;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      curr += nums[i] % 2;
      ans += sum[curr - k];
      sum[curr]++;
    }
    return ans;
  }
};
