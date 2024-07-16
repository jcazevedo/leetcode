// 2096. Step-By-Step Directions From a Binary Tree Node to Another
// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/

#include <string>
#include <unordered_map>
#include <utility>

using namespace std;

#define MAXN 100000

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
  void buildGraph(TreeNode* root, unordered_map<int, TreeNode*>& nodes, unordered_map<int, TreeNode*>& parents) {
    if (root != nullptr) {
      nodes[root->val] = root;
      if (root->left != nullptr) {
        parents[root->left->val] = root;
        buildGraph(root->left, nodes, parents);
      }
      if (root->right != nullptr) {
        parents[root->right->val] = root;
        buildGraph(root->right, nodes, parents);
      }
    }
  }

  string dfs(TreeNode* node, int from, int destValue, unordered_map<int, TreeNode*>& parents, string& path) {
    if (node != nullptr) {
      if (node->val == destValue) { return path; }
      if (parents.find(node->val) != parents.end()) {
        TreeNode* parent = parents[node->val];
        if (parent->val != from) {
          path += "U";
          string next = dfs(parent, node->val, destValue, parents, path);
          if (next != "-1") { return next; }
          path.pop_back();
        }
      }
      if (node->left != nullptr) {
        TreeNode* left = node->left;
        if (left->val != from) {
          path += "L";
          string next = dfs(left, node->val, destValue, parents, path);
          if (next != "-1") { return next; }
          path.pop_back();
        }
      }
      if (node->right != nullptr) {
        TreeNode* right = node->right;
        if (right->val != from) {
          path += "R";
          string next = dfs(right, node->val, destValue, parents, path);
          if (next != "-1") { return next; }
          path.pop_back();
        }
      }
    }
    return "-1";
  }

 public:
  string getDirections(TreeNode* root, int startValue, int destValue) {
    unordered_map<int, TreeNode*> nodes, parents;
    buildGraph(root, nodes, parents);
    string path = "";
    return dfs(nodes[startValue], -1, destValue, parents, path);
  }
};
