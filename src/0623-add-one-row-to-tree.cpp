// 623. Add One Row to Tree
// https://leetcode.com/problems/add-one-row-to-tree/

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
  TreeNode *addOneRow(TreeNode *root, int val, int depth, bool fromLeft = true) {
    if (depth == 1) return new TreeNode(val, fromLeft ? root : nullptr, !fromLeft ? root : nullptr);

    if (root == nullptr) return root;

    root->left = addOneRow(root->left, val, depth - 1, true);
    root->right = addOneRow(root->right, val, depth - 1, false);
    return root;
  }
};
