// 2458. Height of Binary Tree After Subtree Removal Queries
// https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/

#include <algorithm>
#include <vector>

using namespace std;

#ifdef LOCAL
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
#endif

class Solution {
 private:
  void traverseLeft(TreeNode* node, int currHeight, int& maxHeight, vector<int>& maxHeights) {
    if (node == nullptr) { return; }
    maxHeights[node->val] = max(maxHeights[node->val], maxHeight);
    maxHeight = max(maxHeight, currHeight);
    traverseLeft(node->left, currHeight + 1, maxHeight, maxHeights);
    traverseLeft(node->right, currHeight + 1, maxHeight, maxHeights);
  }

  void traverseRight(TreeNode* node, int currHeight, int& maxHeight, vector<int>& maxHeights) {
    if (node == nullptr) { return; }
    maxHeights[node->val] = max(maxHeights[node->val], maxHeight);
    maxHeight = max(maxHeight, currHeight);
    traverseRight(node->right, currHeight + 1, maxHeight, maxHeights);
    traverseRight(node->left, currHeight + 1, maxHeight, maxHeights);
  }

 public:
  vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
    vector<int> maxHeights(10e5 + 1);
    int maxHeight = 0;
    traverseLeft(root, 0, maxHeight, maxHeights);
    maxHeight = 0;
    traverseRight(root, 0, maxHeight, maxHeights);
    vector<int> ans;
    for (int query : queries) { ans.push_back(maxHeights[query]); }
    return ans;
  }
};
