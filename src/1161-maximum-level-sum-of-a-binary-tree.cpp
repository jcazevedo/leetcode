// 1161. Maximum Level Sum of a Binary Tree
// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

#include <algorithm>
#include <limits>
#include <unordered_map>

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
  int levels = 0;
  unordered_map<int, int> levelSum;

  void go(TreeNode* curr, int level) {
    levels = max(levels, level);
    levelSum[level] += curr->val;
    if (curr->left != nullptr) go(curr->left, level + 1);
    if (curr->right != nullptr) go(curr->right, level + 1);
  }

 public:
  int maxLevelSum(TreeNode* root) {
    go(root, 1);
    int ans = 0, best = numeric_limits<int>::min();
    for (int level = 1; level <= levels; ++level)
      if (levelSum[level] > best) {
        best = levelSum[level];
        ans = level;
      }
    return ans;
  }
};
