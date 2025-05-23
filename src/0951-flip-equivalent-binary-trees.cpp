// 951. Flip Equivalent Binary Trees
// https://leetcode.com/problems/flip-equivalent-binary-trees/

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
  bool flipEquiv(TreeNode *root1, TreeNode *root2) {
    if (root1 == nullptr) { return root2 == nullptr; }
    if (root2 == nullptr) { return root1 == nullptr; }
    if (root1->val != root2->val) { return false; }
    return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
           (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
  }
};
