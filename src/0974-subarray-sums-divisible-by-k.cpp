// 974. Subarray Sums Divisible by K
// https://leetcode.com/problems/subarray-sums-divisible-by-k/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int subarraysDivByK(vector<int>& nums, int k) {
    int ans = 0;
    unordered_map<int, int> prev;
    prev[0] = 1;
    int n = nums.size();
    int curr = 0;
    for (int i = 0; i < n; ++i) {
      curr = (curr + nums[i] % k + k) % k;
      ans += prev[curr];
      prev[curr]++;
    }
    return ans;
  }
};
