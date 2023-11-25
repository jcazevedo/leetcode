// 450. Delete Node in a BST
// https://leetcode.com/problems/delete-node-in-a-bst/description/

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
  TreeNode* addLeftmost(TreeNode* root, TreeNode* toAdd) {
    if (root->left == nullptr)
      root->left = toAdd;
    else
      root->left = addLeftmost(root->left, toAdd);
    return root;
  }

public:
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr)
      return root;
    if (root->val == key)
      if (root->left == nullptr && root->right == nullptr)
        return nullptr;
      else if (root->left == nullptr && root->right != nullptr)
        return root->right;
      else if (root->left != nullptr && root->right == nullptr)
        return root->left;
      else
        return addLeftmost(root->right, root->left);
    else if (key < root->val)
      root->left = deleteNode(root->left, key);
    else
      root->right = deleteNode(root->right, key);
    return root;
  }
};
