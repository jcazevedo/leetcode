// 236. Lowest Common Ancestor of a Binary Tree
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root->val == p->val || root->val == q->val) return root;
    if (root->left == nullptr && root->right == nullptr) return nullptr;
    if (root->left == nullptr) return lowestCommonAncestor(root->right, p, q);
    if (root->right == nullptr) return lowestCommonAncestor(root->left, p, q);
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left == nullptr) return right;
    if (right == nullptr) return left;
    if ((left->val == p->val && right->val == q->val) ||
        (left->val == q->val && right->val == p->val) ||
        (root->val == p->val &&
         (right->val == q->val || left->val == q->val)) ||
        (root->val == q->val && (right->val == p->val || left->val == p->val)))
      return root;
    return nullptr;
  }
};
