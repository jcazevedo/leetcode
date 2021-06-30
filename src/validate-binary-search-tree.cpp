#include <climits>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
  bool isValidBST(TreeNode *root, long long left, long long right) {
    if (root == nullptr)
      return true;
    if (root->val <= left || root->val >= right)
      return false;
    return isValidBST(root->left, left, root->val) && isValidBST(root->right, root->val, right);
  }

public:
  bool isValidBST(TreeNode *root) { return isValidBST(root, LLONG_MIN, LLONG_MAX); }
};
