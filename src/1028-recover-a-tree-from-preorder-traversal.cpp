// 1028. Recover a Tree From Preorder Traversal
// https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/

#include <stack>
#include <string>
#include <utility>

using namespace std;

#ifdef LOCAL
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif

class Solution {
 public:
  TreeNode *recoverFromPreorder(string traversal) {
    int n = traversal.size();
    stack<pair<int, TreeNode *>> s;
    TreeNode *root = new TreeNode();
    root->val = 0;
    int i;
    for (i = 0; traversal[i] != '-' && i < n; ++i) {
      root->val *= 10;
      root->val += (traversal[i] - '0');
    }
    s.push({0, root});
    while (i < n) {
      int depth = 0;
      while (traversal[i] == '-') {
        ++depth;
        ++i;
      }
      TreeNode *node = new TreeNode();
      node->val = 0;
      while (i < n && traversal[i] != '-') {
        node->val *= 10;
        node->val += (traversal[i] - '0');
        ++i;
      }
      while (s.top().first != depth - 1) { s.pop(); }
      if (s.top().second->left == nullptr) {
        s.top().second->left = node;
      } else {
        s.top().second->right = node;
      }
      s.push({depth, node});
    }
    return root;
  }
};
