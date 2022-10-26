// 173. Binary Search Tree Iterator
// https://leetcode.com/problems/binary-search-tree-iterator/

#include <stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class BSTIterator {
 private:
  stack<TreeNode*> visited;

 public:
  BSTIterator(TreeNode* root) {
    while (root != nullptr) {
      visited.push(root);
      root = root->left;
    }
  }

  int next() {
    TreeNode* curr = visited.top();
    visited.pop();
    int ans = curr->val;
    if (curr->right != nullptr) {
      curr = curr->right;
      while (curr != nullptr) {
        visited.push(curr);
        curr = curr->left;
      }
    }
    return ans;
  }

  bool hasNext() { return !visited.empty(); }
};
