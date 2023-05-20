// 1008. Construct Binary Search Tree from Preorder Traversal
// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

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
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    if (preorder.empty())
      return nullptr;
    int root = preorder[0];
    TreeNode* node = new TreeNode(root);
    vector<int> left, right;
    int N = preorder.size();
    for (int i = 1; i < N; ++i)
      (preorder[i] < root ? left : right).push_back(preorder[i]);
    node->left = bstFromPreorder(left);
    node->right = bstFromPreorder(right);
    return node;
  }
};
