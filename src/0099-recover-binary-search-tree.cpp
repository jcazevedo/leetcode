// 99. Recover Binary Search Tree
// https://leetcode.com/problems/recover-binary-search-tree/

#include <algorithm>
#include <cassert>
#include <limits>

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
  TreeNode* prev = nullptr;
  TreeNode* first = nullptr;
  TreeNode* second = nullptr;

  void go(TreeNode* root) {
    if (root == nullptr) { return; }
    go(root->left);
    if (first == nullptr && root->val < prev->val) { first = prev; }
    if (first != nullptr && root->val < prev->val) { second = root; }
    prev = root;
    go(root->right);
  }

 public:
  void recoverTree(TreeNode* root) {
    prev = new TreeNode(numeric_limits<int>::min());
    go(root);
    assert(first != nullptr);
    assert(second != nullptr);
    swap(first->val, second->val);
  }
};
