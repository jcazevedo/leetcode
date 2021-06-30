struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
  bool isSymmetricAux(TreeNode *left, TreeNode *right) {
    if (left == nullptr && right == nullptr)
      return true;
    if (left == nullptr || right == nullptr)
      return false;
    bool outer = isSymmetricAux(left->left, right->right);
    if (!outer)
      return outer;
    if (left->val != right->val)
      return false;
    return isSymmetricAux(left->right, right->left);
  }

public:
  bool isSymmetric(TreeNode *root) { return isSymmetricAux(root, root); }
};
