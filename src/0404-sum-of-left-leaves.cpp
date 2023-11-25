// 404. Sum of Left Leaves
// https://leetcode.com/problems/sum-of-left-leaves/

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 private:
  int sumOfLeftLeavesAux(TreeNode* root, bool isLeft) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr)
      return isLeft ? root->val : 0;
    return sumOfLeftLeavesAux(root->left, true) +
           sumOfLeftLeavesAux(root->right, false);
  }

 public:
  int sumOfLeftLeaves(TreeNode* root) {
    return sumOfLeftLeavesAux(root, false);
  }
};
