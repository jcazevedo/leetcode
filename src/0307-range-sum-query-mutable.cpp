// 307. Range Sum Query - Mutable
// https://leetcode.com/problems/range-sum-query-mutable/

#include <vector>

using namespace std;

class NumArray {
 private:
  int N;
  vector<int> bit;
  vector<int> prev;

  int sumUntil(int index) {
    int ans = 0;
    while (index >= 0) {
      ans += bit[index];
      index = (index & (index + 1)) - 1;
    }
    return ans;
  }

 public:
  NumArray(vector<int>& nums) {
    N = nums.size();
    bit = vector<int>(N, 0);
    prev = vector<int>(N, 0);
    for (int i = 0; i < N; ++i) update(i, nums[i]);
  }

  void update(int index, int val) {
    int diff = val - prev[index];
    prev[index] = val;
    while (index < N) {
      bit[index] += diff;
      index = index | (index + 1);
    }
  }

  int sumRange(int left, int right) {
    return sumUntil(right) - sumUntil(left - 1);
  }
};
