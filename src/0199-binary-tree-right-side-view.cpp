// 199. Binary Tree Right Side View
// https://leetcode.com/problems/binary-tree-right-side-view/

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
  vector<int> rightmost;

  void dfs(TreeNode* root, int level = 0) {
    if (root == nullptr)
      return;
    if (level >= (int)rightmost.size())
      rightmost.push_back(root->val);
    else
      rightmost[level] = root->val;
    dfs(root->left, level + 1);
    dfs(root->right, level + 1);
  }

public:
  vector<int> rightSideView(TreeNode* root) {
    dfs(root);
    return rightmost;
  }
};
