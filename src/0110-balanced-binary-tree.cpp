// 110. Balanced Binary Tree
// https://leetcode.com/problems/balanced-binary-tree/

#include <algorithm>

using namespace std;

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
  int height(TreeNode* root) {
    if (root == nullptr)
      return 0;
    return 1 + max(height(root->left), height(root->right));
  }

public:
  bool isBalanced(TreeNode* root) {
    if (root == nullptr)
      return true;
    return isBalanced(root->left) && isBalanced(root->right) &&
           abs(height(root->left) - height(root->right)) <= 1;
  }
};
