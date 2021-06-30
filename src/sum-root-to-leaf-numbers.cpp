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
  int sumNumbers(TreeNode *root, int curr = 0) {
    if (root == nullptr)
      return 0;
    int next = curr + root->val;
    bool is_leaf = root->left == nullptr && root->right == nullptr;
    if (is_leaf)
      return next;
    int tot = 0;
    if (root->left != nullptr)
      tot += sumNumbers(root->left, next * 10);
    if (root->right != nullptr)
      tot += sumNumbers(root->right, next * 10);
    return tot;
  }
};
