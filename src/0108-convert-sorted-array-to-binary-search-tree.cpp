// 108. Convert Sorted Array to Binary Search Tree
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 private:
  TreeNode* go(const vector<int>& nums, int from, int to) {
    int mid = from + (to - from) / 2;
    return new TreeNode(nums[mid],
                        from < mid ? go(nums, from, mid - 1) : nullptr,
                        mid < to ? go(nums, mid + 1, to) : nullptr);
  }

 public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    int N = nums.size();
    return go(nums, 0, N - 1);
  }
};
