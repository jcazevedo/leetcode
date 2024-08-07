// 226. Invert Binary Tree
// https://leetcode.com/problems/invert-binary-tree/

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
  TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) return root;
    TreeNode* left_inv = invertTree(root->left);
    TreeNode* right_inv = invertTree(root->right);
    root->left = right_inv;
    root->right = left_inv;
    return root;
  }
};
