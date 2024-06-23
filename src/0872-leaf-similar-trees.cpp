// 872. Leaf-Similar Trees
// https://leetcode.com/problems/leaf-similar-trees/

#include <vector>

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
  void leafValueSequence(TreeNode* root, vector<int>& curr) {
    if (root == nullptr || (root->left == nullptr && root->right == nullptr)) curr.push_back(root->val);
    if (root->left != nullptr) leafValueSequence(root->left, curr);
    if (root->right != nullptr) leafValueSequence(root->right, curr);
  }

 public:
  bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> v1, v2;
    leafValueSequence(root1, v1);
    leafValueSequence(root2, v2);
    return v1 == v2;
  }
};
