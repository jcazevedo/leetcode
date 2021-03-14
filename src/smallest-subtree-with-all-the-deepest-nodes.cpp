#include <algorithm>
#include <unordered_map>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left),
                                                     right(right) {}
};

class Solution {
private:
  unordered_map<TreeNode*, int> depth_cache;

  int depth(TreeNode* root) {
    if (root == nullptr) { return 0; }
    if (depth_cache.count(root) == 0) {
      depth_cache[root] = max(depth(root->left), depth(root->right)) + 1;
    }
    return depth_cache[root];
  }

public:
  TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    if (root == nullptr) { return root; }
    int depth_left = depth(root->left);
    int depth_right = depth(root->right);
    if (depth_left == depth_right)
      return root;
    if (depth_left > depth_right)
      return subtreeWithAllDeepest(root->left);
    return subtreeWithAllDeepest(root->right);
  }
};
