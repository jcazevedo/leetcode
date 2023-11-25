// 230. Kth Smallest Element in a BST
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 private:
  int i = 0;

  TreeNode* aux(TreeNode* root, int k) {
    if (root == nullptr) return root;
    TreeNode* l = aux(root->left, k);
    if (l != nullptr) return l;
    i++;
    if (i == k) return root;
    return aux(root->right, k);
  }

 public:
  int kthSmallest(TreeNode* root, int k) {
    i = 0;
    return aux(root, k)->val;
  }
};
