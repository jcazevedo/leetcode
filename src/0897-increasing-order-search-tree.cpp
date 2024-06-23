// 897. Increasing Order Search Tree
// https://leetcode.com/problems/increasing-order-search-tree/

#include <map>

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
  pair<TreeNode*, TreeNode*> in_order_traversal(TreeNode* root) {
    if (root == nullptr) return make_pair(nullptr, nullptr);
    TreeNode* start;
    TreeNode* end;
    pair<TreeNode*, TreeNode*> left = in_order_traversal(root->left);
    pair<TreeNode*, TreeNode*> right = in_order_traversal(root->right);
    if (left.first != nullptr) {
      start = left.first;
      left.second->right = root;
    } else {
      start = root;
    }
    if (right.first != nullptr) {
      root->right = right.first;
      end = right.second;
    } else {
      end = root;
    }
    root->left = nullptr;
    return make_pair(start, end);
  }

 public:
  TreeNode* increasingBST(TreeNode* root) {
    if (root == nullptr) return root;
    return in_order_traversal(root).first;
  }
};
