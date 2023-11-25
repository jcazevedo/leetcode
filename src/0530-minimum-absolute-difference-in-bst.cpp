// 530. Minimum Absolute Difference in BST
// https://leetcode.com/problems/minimum-absolute-difference-in-bst/

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
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 private:
  long long getMinimumDifferenceAux(TreeNode* root,
                                    long long left,
                                    long long right) {
    long long diffLeft = abs(root->val - left);
    long long diffRight = abs(root->val - right);
    long long ans = min(diffLeft, diffRight);
    if (root->left != nullptr)
      ans = min(ans, getMinimumDifferenceAux(root->left, left, root->val));
    if (root->right != nullptr)
      ans = min(ans, getMinimumDifferenceAux(root->right, root->val, right));
    return ans;
  }

 public:
  int getMinimumDifference(TreeNode* root) {
    return getMinimumDifferenceAux(root, numeric_limits<int>::min(),
                                   numeric_limits<int>::max());
  }
};
