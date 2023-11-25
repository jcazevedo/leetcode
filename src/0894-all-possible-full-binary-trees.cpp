// 894. All Possible Full Binary Trees
// https://leetcode.com/problems/all-possible-full-binary-trees/

#include <vector>

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
public:
  vector<TreeNode*> allPossibleFBT(int n) {
    if (n % 2 == 0)
      return {};
    if (n == 1)
      return {new TreeNode(0)};

    vector<TreeNode*> ans;
    for (int i = 1; i <= n - 1; ++i) {
      vector<TreeNode*> left = allPossibleFBT(i);
      vector<TreeNode*> right = allPossibleFBT(n - 1 - i);
      for (TreeNode* l : left) {
        if (i == n - 1) {
          TreeNode* root = new TreeNode(0);
          root->left = l;
          ans.push_back(root);
        }
        for (TreeNode* r : right) {
          TreeNode* root = new TreeNode(0);
          root->left = l;
          root->right = r;
          ans.push_back(root);
        }
      }
    }

    return ans;
  }
};
