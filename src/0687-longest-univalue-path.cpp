// 687. Longest Univalue Path
// https://leetcode.com/problems/longest-univalue-path/

#include <algorithm>

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
  int bestStart(TreeNode *root) {
    if (root == nullptr) { return 0; }
    int best = 0;
    if (root->left != nullptr && root->left->val == root->val) { best = max(best, 1 + bestStart(root->left)); }
    if (root->right != nullptr && root->right->val == root->val) { best = max(best, 1 + bestStart(root->right)); }
    return best;
  }

 public:
  int longestUnivaluePath(TreeNode *root) {
    if (root == nullptr) { return 0; }
    int atStart = 0;
    if (root->left != nullptr && root->left->val == root->val) { atStart += 1 + bestStart(root->left); }
    if (root->right != nullptr && root->right->val == root->val) { atStart += 1 + bestStart(root->right); }
    return max(max(atStart, longestUnivaluePath(root->left)), longestUnivaluePath(root->right));
  }
};
