// 315. Count of Smaller Numbers After Self
// https://leetcode.com/problems/count-of-smaller-numbers-after-self/

#include <algorithm>
#include <vector>

using namespace std;

class FenwickTree {
 private:
  vector<int> bits;
  int l;

 public:
  FenwickTree(int n) {
    l = n;
    bits.resize(l);
  }

  void update(int n) {
    ++n;
    while (n < l) {
      ++bits[n];
      n += (n & (-n));
    }
  }

  int find(int n) {
    int ans = 0;
    while (n > 0) {
      ans += bits[n];
      n -= (n & (-n));
    }
    return ans;
  }
};

class Solution {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);
    int lo = *min_element(nums.begin(), nums.end());
    int hi = *max_element(nums.begin(), nums.end());
    FenwickTree tree(hi - lo + 2);
    for (int i = n - 1; i >= 0; --i) {
      ans[i] = tree.find(nums[i] - lo);
      tree.update(nums[i] - lo);
    }
    return ans;
  }
};
