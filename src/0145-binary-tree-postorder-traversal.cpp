// 145. Binary Tree Postorder Traversal
// https://leetcode.com/problems/binary-tree-postorder-traversal/

#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
private:
  void traversal(TreeNode* root, vector<int>& ans) {
    if (root == nullptr)
      return;
    traversal(root->left, ans);
    traversal(root->right, ans);
    ans.push_back(root->val);
  }

public:
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    traversal(root, ans);
    return ans;
  }
};
