// 1038. Binary Search Tree to Greater Sum Tree
// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
 private:
  int toGreatSumTree(TreeNode *root, int sumToRight) {
    if (root == nullptr) { return 0; }
    int sumRight = root->right != nullptr ? toGreatSumTree(root->right, sumToRight) : 0;
    int sumLeft = root->left != nullptr ? toGreatSumTree(root->left, sumRight + root->val + sumToRight) : 0;
    int tot = sumRight + sumLeft + root->val;
    root->val += sumRight + sumToRight;
    return tot;
  }

 public:
  TreeNode *bstToGst(TreeNode *root) {
    toGreatSumTree(root, 0);
    return root;
  }
};
