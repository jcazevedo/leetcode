// 94. Binary Tree Inorder Traversal
// https://leetcode.com/problems/binary-tree-inorder-traversal/

#include <stack>
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
  vector<int> inorderTraversal(TreeNode* root) {
    if (root == nullptr) return vector<int>();
    vector<int> res;
    stack<TreeNode*> s;
    s.push(root);
    TreeNode* curr = root;
    while (curr->left != nullptr) {
      s.push(curr->left);
      curr = curr->left;
    }
    while (!s.empty()) {
      TreeNode* curr = s.top();
      s.pop();
      res.push_back(curr->val);
      if (curr->right != nullptr) {
        s.push(curr->right);
        curr = curr->right;
        while (curr->left != nullptr) {
          s.push(curr->left);
          curr = curr->left;
        }
      }
    }
    return res;
  }
};
