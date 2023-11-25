// 671. Second Minimum Node In a Binary Tree
// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/

#include <algorithm>

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
  int dfs(TreeNode* root, int minVal) {
    if (root == nullptr) return -1;
    if (root->left == nullptr) {
      if (root->val != minVal) return root->val;
      return -1;
    }
    int left = dfs(root->left, minVal);
    int right = dfs(root->right, minVal);
    if (left == -1) return right;
    if (right == -1) return left;
    return min(left, right);
  }

 public:
  int findSecondMinimumValue(TreeNode* root) { return dfs(root, root->val); }
};
