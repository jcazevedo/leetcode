// 1382. Balance a Binary Search Tree
// https://leetcode.com/problems/balance-a-binary-search-tree/

#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
 private:
  void traverseInOrder(TreeNode *root, vector<TreeNode *> &nodes) {
    if (root == nullptr) { return; }
    traverseInOrder(root->left, nodes);
    nodes.push_back(root);
    traverseInOrder(root->right, nodes);
  }

  TreeNode *rebuildTree(vector<TreeNode *> &nodes, int from, int to) {
    if (from > to) { return nullptr; }
    int mid = (from + to) / 2;
    TreeNode *root = nodes[mid];
    root->left = rebuildTree(nodes, from, mid - 1);
    root->right = rebuildTree(nodes, mid + 1, to);
    return root;
  }

 public:
  TreeNode *balanceBST(TreeNode *root) {
    vector<TreeNode *> nodes;
    traverseInOrder(root, nodes);
    int n = nodes.size();
    return rebuildTree(nodes, 0, n - 1);
  }
};
