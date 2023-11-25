// 1022. Sum of Root To Leaf Binary Numbers
// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

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
  void dfs(TreeNode* curr, int curr_value, int& curr_sum) {
    if (curr == nullptr)
      return;
    bool is_leaf = curr->left == nullptr && curr->right == nullptr;
    curr_value = curr_value * 2 + curr->val;
    if (is_leaf)
      curr_sum += curr_value;
    if (curr->left != nullptr)
      dfs(curr->left, curr_value, curr_sum);
    if (curr->right != nullptr)
      dfs(curr->right, curr_value, curr_sum);
  }

public:
  int sumRootToLeaf(TreeNode* root) {
    int ans = 0;
    dfs(root, 0, ans);
    return ans;
  }
};
