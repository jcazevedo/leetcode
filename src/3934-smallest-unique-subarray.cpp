// 3934. Smallest Unique Subarray
// https://leetcode.com/problems/smallest-unique-subarray/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int smallestUniqueSubarray(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) { return n; }
    vector<int> sa(n);
    vector<int> rank(n);
    vector<int> next_rank(n);
    for (int i = 0; i < n; ++i) { sa[i] = i; }
    sort(sa.begin(), sa.end(), [&](int a, int b) { return nums[a] < nums[b]; });
    for (int i = 1; i < n; ++i) { rank[sa[i]] = rank[sa[i - 1]] + (nums[sa[i]] != nums[sa[i - 1]]); }
    vector<int> shifted(n);
    vector<int> count(n);
    int classes = rank[sa[n - 1]] + 1;
    for (int len = 1; len < n && classes < n; len *= 2) {
      int size = 0;
      for (int i = n - len; i < n; ++i) { shifted[size++] = i; }
      for (int i = 0; i < n; ++i) {
        if (sa[i] >= len) { shifted[size++] = sa[i] - len; }
      }
      fill(count.begin(), count.begin() + classes, 0);
      for (int i = 0; i < n; ++i) { ++count[rank[shifted[i]]]; }
      for (int i = 1; i < classes; ++i) { count[i] += count[i - 1]; }
      for (int i = n - 1; i >= 0; --i) {
        int index = shifted[i];
        sa[--count[rank[index]]] = index;
      }
      next_rank[sa[0]] = 0;
      for (int i = 1; i < n; ++i) {
        int a = sa[i - 1];
        int b = sa[i];
        int ra = a + len < n ? rank[a + len] : -1;
        int rb = b + len < n ? rank[b + len] : -1;
        bool different = rank[a] != rank[b] || ra != rb;
        next_rank[b] = next_rank[a] + different;
      }
      classes = next_rank[sa[n - 1]] + 1;
      rank.swap(next_rank);
    }
    vector<int> lcp(n + 1);
    int common = 0;
    for (int i = 0; i < n; ++i) {
      int r = rank[i];
      if (r == 0) {
        common = 0;
        continue;
      }
      int j = sa[r - 1];
      while (i + common < n && j + common < n && nums[i + common] == nums[j + common]) { ++common; }
      lcp[r] = common;
      if (common > 0) { --common; }
    }
    int ans = n;
    for (int r = 0; r < n; ++r) {
      int len = max(lcp[r], lcp[r + 1]) + 1;
      if (len <= n - sa[r]) { ans = min(ans, len); }
    }
    return ans;
  }
};
