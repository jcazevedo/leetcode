// 144. Binary Tree Preorder Traversal
// https://leetcode.com/problems/binary-tree-preorder-traversal/

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
 private:
  void go(TreeNode* curr, vector<int>& traversal) {
    traversal.push_back(curr->val);
    if (curr->left != nullptr) go(curr->left, traversal);
    if (curr->right != nullptr) go(curr->right, traversal);
  }

 public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    if (root == nullptr) return ans;
    go(root, ans);
    return ans;
  }
};
