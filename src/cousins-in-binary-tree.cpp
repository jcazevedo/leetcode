#include <map>

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
  pair<int, int> depth_and_parent(TreeNode* root, int x, int depth = 0, int parent = -1) {
    if (root == nullptr)
      return {-1, -1};
    if (root->val == x)
      return {depth, parent};
    pair<int, int> left = depth_and_parent(root->left, x, depth + 1, root->val);
    if (left.first != -1)
      return left;
    return depth_and_parent(root->right, x, depth + 1, root->val);
  }

public:
  bool isCousins(TreeNode* root, int x, int y) {
    pair<int, int> xx = depth_and_parent(root, x);
    pair<int, int> yy = depth_and_parent(root, y);
    return xx.first != -1 && yy.first != -1 && xx.first == yy.first && xx.second != yy.second;
  }
};
