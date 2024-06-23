// 572. Subtree of Another Tree
// https://leetcode.com/problems/subtree-of-another-tree/

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
  bool isSubtree(TreeNode *root, TreeNode *subRoot, bool inSubtree = false) {
    if (root == nullptr && subRoot != nullptr) return false;

    if (root != nullptr && subRoot == nullptr) return false;

    if (root == nullptr && subRoot == nullptr) return true;

    bool currentSubTree = false;
    if (root->val == subRoot->val)
      currentSubTree = isSubtree(root->left, subRoot->left, true) && isSubtree(root->right, subRoot->right, true);
    if (currentSubTree) return true;
    if (inSubtree) return false;

    return isSubtree(root->left, subRoot, false) || isSubtree(root->right, subRoot, false);
  }
};
