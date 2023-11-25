// 106. Construct Binary Search Tree from Inorder and Postorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

#include <vector>

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
 public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.empty() && postorder.empty()) return nullptr;
    int root_val = postorder.back();
    vector<int> inorder_left, inorder_right;
    bool go_left = true;
    for (int v : inorder) {
      if (v == root_val) {
        go_left = false;
      } else {
        if (go_left)
          inorder_left.push_back(v);
        else
          inorder_right.push_back(v);
      }
    }
    vector<int> postorder_left, postorder_right;
    int i = 0;
    while (postorder_left.size() < inorder_left.size())
      postorder_left.push_back(postorder[i++]);
    while (postorder_right.size() < inorder_right.size())
      postorder_right.push_back(postorder[i++]);
    TreeNode* root = new TreeNode(root_val);
    root->left = buildTree(inorder_left, postorder_left);
    root->right = buildTree(inorder_right, postorder_right);
    return root;
  }
};
