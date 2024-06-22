// 560. Subarray Sum Equals K
// https://leetcode.com/problems/subarray-sum-equals-k/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    int N = nums.size();
    unordered_map<int, int> prev;
    int curr = 0, cnt = 0;
    prev[0] = 1;
    for (int i = 0; i < N; ++i) {
      curr += nums[i];
      cnt += prev[curr - k];
      prev[curr]++;
    }
    return cnt;
  }
};
