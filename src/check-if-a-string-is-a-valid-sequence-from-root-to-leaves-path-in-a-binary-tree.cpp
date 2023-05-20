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
  bool dfs(TreeNode* root, vector<int>& arr, int i) {
    if (i >= arr.size() || arr[i] != root->val)
      return false;
    bool is_leaf = root->left == nullptr && root->right == nullptr;
    if (is_leaf)
      return i == arr.size() - 1;
    return (root->left != nullptr ? dfs(root->left, arr, i + 1) : false) ||
           (root->right != nullptr ? dfs(root->right, arr, i + 1) : false);
  }

public:
  bool isValidSequence(TreeNode* root, vector<int>& arr) { return dfs(root, arr, 0); }
};
