// 2641. Cousins in Binary Tree II
// https://leetcode.com/problems/cousins-in-binary-tree-ii/

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
  void computeSums(TreeNode* curr,
                   TreeNode* parent,
                   int level,
                   unordered_map<int, int>& levelSum,
                   unordered_map<TreeNode*, int>& childSum) {
    levelSum[level] += curr->val;
    childSum[parent] += curr->val;
    if (curr->left != nullptr) { computeSums(curr->left, curr, level + 1, levelSum, childSum); }
    if (curr->right != nullptr) { computeSums(curr->right, curr, level + 1, levelSum, childSum); }
  }

  void setCousinsSum(TreeNode* curr,
                     TreeNode* parent,
                     int level,
                     unordered_map<int, int>& levelSum,
                     unordered_map<TreeNode*, int>& childSum) {
    curr->val = levelSum[level] - childSum[parent];
    if (curr->left != nullptr) { setCousinsSum(curr->left, curr, level + 1, levelSum, childSum); }
    if (curr->right != nullptr) { setCousinsSum(curr->right, curr, level + 1, levelSum, childSum); }
  }

 public:
  TreeNode* replaceValueInTree(TreeNode* root) {
    unordered_map<int, int> levelSum;
    unordered_map<TreeNode*, int> childSum;
    computeSums(root, nullptr, 1, levelSum, childSum);
    setCousinsSum(root, nullptr, 1, levelSum, childSum);
    return root;
  }
};
