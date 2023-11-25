// 111. Minimum Depth of Binary Tree
// https://leetcode.com/problems/minimum-depth-of-binary-tree/

#include <algorithm>
#include <climits>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  int minDepth(TreeNode* root) {
    if (root == nullptr) return 0;

    if (root->left == nullptr && root->right == nullptr) return 1;

    int left_min = root->left != nullptr ? minDepth(root->left) : INT_MAX;
    int right_min = root->right != nullptr ? minDepth(root->right) : INT_MAX;

    return 1 + min(left_min, right_min);
  }
};
