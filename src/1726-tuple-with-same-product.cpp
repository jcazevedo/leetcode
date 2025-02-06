// 1726. Tuple with Same Product
// https://leetcode.com/problems/tuple-with-same-product/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int tupleSameProduct(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) { cnt[nums[i] * nums[j]] += 2; }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) { ans += 2 * (cnt[nums[i] * nums[j]] - 2); }
    }
    return ans;
  }
};
