// 889. Construct Binary Tree from Preorder and Postorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/

#include <vector>

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
 public:
  TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder) {
    if (preorder.empty() && postorder.empty()) { return nullptr; }
    TreeNode *root = new TreeNode(preorder[0]);
    int n = preorder.size();
    vector<int> preorderL, postorderL, preorderR, postorderR;
    if (preorder.size() > 1) {
      int next = preorder[1];
      bool left = true;
      for (int i = 1; i < n; ++i) {
        if (left) {
          preorderL.push_back(preorder[i]);
          postorderL.push_back(postorder[i - 1]);
        } else {
          preorderR.push_back(preorder[i]);
          postorderR.push_back(postorder[i - 1]);
        }
        if (postorder[i - 1] == next) { left = false; }
      }
    }
    root->left = constructFromPrePost(preorderL, postorderL);
    root->right = constructFromPrePost(preorderR, postorderR);
    return root;
  }
};
