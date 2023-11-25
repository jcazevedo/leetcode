// 863. All Nodes Distance K in Binary Tree
// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
  void setParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent,
                  TreeNode* prev = nullptr) {
    if (root != nullptr) {
      parent[root] = prev;
      setParents(root->left, parent, root);
      setParents(root->right, parent, root);
    }
  }

  void visit(TreeNode* curr, unordered_map<TreeNode*, TreeNode*>& parent, int k,
             vector<int>& ans, TreeNode* prev = nullptr) {
    if (curr != nullptr) {
      if (k == 0)
        ans.push_back(curr->val);
      else {
        if (curr->left != prev)
          visit(curr->left, parent, k - 1, ans, curr);
        if (curr->right != prev)
          visit(curr->right, parent, k - 1, ans, curr);
        if (parent[curr] != prev)
          visit(parent[curr], parent, k - 1, ans, curr);
      }
    }
  }

public:
  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> parent;
    setParents(root, parent);
    vector<int> ans;
    visit(target, parent, k, ans);
    return ans;
  }
};
