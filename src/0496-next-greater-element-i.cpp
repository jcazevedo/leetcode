// 496. Next Greater Element I
// https://leetcode.com/problems/next-greater-element-i/

#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> nextLargest;
    int n2 = nums2.size();
    stack<int> s;
    for (int i = n2 - 1; i >= 0; --i) {
      while (!s.empty() && s.top() < nums2[i]) { s.pop(); }
      if (s.empty()) {
        nextLargest[nums2[i]] = -1;
      } else {
        nextLargest[nums2[i]] = s.top();
      }
      s.push(nums2[i]);
    }
    int n1 = nums1.size();
    vector<int> ans(n1);
    for (int i = 0; i < n1; ++i) { ans[i] = nextLargest[nums1[i]]; }
    return ans;
  }
};
