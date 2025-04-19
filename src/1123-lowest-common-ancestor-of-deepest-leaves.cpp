// 1123. Lowest Common Ancestor of Deepest Leaves
// https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/

#include <algorithm>
#include <unordered_map>

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
 private:
 private:
  unordered_map<TreeNode *, int> depth_cache;

  int depth(TreeNode *root) {
    if (root == nullptr) { return 0; }
    if (depth_cache.count(root) == 0) { depth_cache[root] = max(depth(root->left), depth(root->right)) + 1; }
    return depth_cache[root];
  }

 public:
  TreeNode *lcaDeepestLeaves(TreeNode *root) {
    if (root == nullptr) { return root; }
    int depth_left = depth(root->left);
    int depth_right = depth(root->right);
    if (depth_left == depth_right) return root;
    if (depth_left > depth_right) return lcaDeepestLeaves(root->left);
    return lcaDeepestLeaves(root->right);
  }
};
