// 1814. Count Nice Pairs in an Array
// https://leetcode.com/problems/count-nice-pairs-in-an-array/

#include <unordered_map>
#include <vector>

using namespace std;

#define MOD 1000000007

class Solution {
private:
  int rev(int n) {
    int ans = 0;
    while (n) {
      ans *= 10;
      ans += n % 10;
      n /= 10;
    }
    return ans;
  }

public:
  int countNicePairs(vector<int>& nums) {
    int N = nums.size();
    unordered_map<int, int> count;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
      int curr = nums[i] - rev(nums[i]);
      ans = (ans + count[curr]) % MOD;
      count[curr]++;
    }
    return ans;
  }
};
