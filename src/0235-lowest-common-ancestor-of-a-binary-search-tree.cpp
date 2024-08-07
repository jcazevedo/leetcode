// 235. Lowest Common Ancestor of a Binary Search Tree
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == p || root == q) return root;
    if (p->val <= root->val && q->val <= root->val) return lowestCommonAncestor(root->left, p, q);
    if (p->val >= root->val && q->val >= root->val) return lowestCommonAncestor(root->right, p, q);
    return root;
  }
};
