// 107. Binary Tree Level Order Traversal II
// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

#include <map>
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
  map<int, vector<int>> res;

  void dfs(TreeNode* root, int level = 0) {
    res[level].push_back(root->val);
    if (root->left != nullptr) dfs(root->left, level + 1);
    if (root->right != nullptr) dfs(root->right, level + 1);
  }

 public:
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    if (root == nullptr) return vector<vector<int>>();
    res.clear();
    dfs(root);
    vector<vector<int>> answer;
    for (auto itr = res.rbegin(); itr != res.rend(); ++itr) {
      answer.push_back(itr->second);
    }
    return answer;
  }
};
