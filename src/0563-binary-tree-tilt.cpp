// 563. Binary Tree Tilt
// https://leetcode.com/problems/binary-tree-tilt/

#include <cstdlib>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 private:
  int ans;

  int dfs(TreeNode* root) {
    if (root == nullptr) return 0;
    int sum_left = dfs(root->left);
    int sum_right = dfs(root->right);
    int diff = abs(sum_left - sum_right);
    ans += diff;
    return sum_left + sum_right + root->val;
  }

 public:
  int findTilt(TreeNode* root) {
    ans = 0;
    dfs(root);
    return ans;
  }
};
