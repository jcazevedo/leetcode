// 105. Construct Binary Tree from Preorder and Inorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty() && inorder.empty()) return nullptr;
    TreeNode* root = new TreeNode(preorder[0]);
    vector<int> il, ir, pl, pr;
    bool l = true;
    int j = 1;
    for (auto i = 0; i < (int)inorder.size(); i++) {
      if (inorder[i] == root->val) {
        l = false;
      } else if (l) {
        il.push_back(inorder[i]);
        pl.push_back(preorder[j++]);
      } else {
        ir.push_back(inorder[i]);
        pr.push_back(preorder[j++]);
      }
    }
    root->left = buildTree(pl, il);
    root->right = buildTree(pr, ir);
    return root;
  }
};
