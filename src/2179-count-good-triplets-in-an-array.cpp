// 2179. Count Good Triplets in an Array
// https://leetcode.com/problems/count-good-triplets-in-an-array/

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
  long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    vector<int> pos(n);
    for (int i = 0; i < n; i++) { pos[nums2[i]] = i; }
    FenwickTree bit(n + 1);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      int p = pos[nums1[i]];
      long long left = bit.find(p);
      long long right = (n - 1 - p) - (i - left);
      ans += left * right;
      bit.update(p);
    }
    return ans;
  }
};
