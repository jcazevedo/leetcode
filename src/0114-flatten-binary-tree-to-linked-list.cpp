// 114. Flatten Binary Tree to Linked List
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

#ifdef LOCAL
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif

class Solution {
 public:
  void flatten(TreeNode *root) {
    if (root == nullptr) { return; }
    flatten(root->left);
    flatten(root->right);
    TreeNode *right = root->right;
    root->right = root->left;
    root->left = nullptr;
    TreeNode *curr = root;
    while (curr->right != nullptr) { curr = curr->right; }
    curr->right = right;
  }
};
