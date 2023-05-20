// 1026. Maximum Difference Between Node and Ancestor
// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

#include <algorithm>
#include <cmath>
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
  int dfs(TreeNode* root, int max_value, int min_value) {
    if (root == nullptr)
      return abs(max_value - min_value);
    int next_max = max(max_value, root->val);
    int next_min = min(min_value, root->val);
    return max(dfs(root->left, next_max, next_min), dfs(root->right, next_max, next_min));
  }

public:
  int maxAncestorDiff(TreeNode* root) { return dfs(root, numeric_limits<int>::min(), numeric_limits<int>::max()); }
};
