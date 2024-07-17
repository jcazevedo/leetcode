// 1110. Delete Nodes And Return Forest
// https://leetcode.com/problems/delete-nodes-and-return-forest/

#include <unordered_set>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
 private:
  void dfs(TreeNode *node, const unordered_set<int> &toDelete, vector<TreeNode *> &ans, bool orphan) {
    if (node == nullptr) { return; }
    bool deleted = toDelete.find(node->val) != toDelete.end();
    if (orphan && !deleted) { ans.push_back(node); }
    dfs(node->left, toDelete, ans, deleted);
    dfs(node->right, toDelete, ans, deleted);
    if (node->left != nullptr && toDelete.find(node->left->val) != toDelete.end()) { node->left = nullptr; }
    if (node->right != nullptr && toDelete.find(node->right->val) != toDelete.end()) { node->right = nullptr; }
  }

 public:
  vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
    vector<TreeNode *> ans;
    unordered_set<int> toDeleteSet;
    for (int v : to_delete) { toDeleteSet.insert(v); }
    dfs(root, toDeleteSet, ans, true);
    return ans;
  }
};
