// 95. Unique Binary Search Trees II
// https://leetcode.com/problems/unique-binary-search-trees-ii/

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
private:
  vector<TreeNode*> go(vector<int> nodesToAssign) {
    if (nodesToAssign.empty())
      return {nullptr};
    vector<TreeNode*> ans;
    for (int node : nodesToAssign) {
      vector<int> nodesLeft, nodesRight;
      for (int other : nodesToAssign) {
        if (other == node)
          continue;
        if (other < node)
          nodesLeft.push_back(other);
        else
          nodesRight.push_back(other);
      }
      vector<TreeNode*> possibleLeft = go(nodesLeft);
      vector<TreeNode*> possibleRight = go(nodesRight);
      for (TreeNode* left : possibleLeft) {
        for (TreeNode* right : possibleRight) {
          TreeNode* root = new TreeNode(node);
          root->left = left;
          root->right = right;
          ans.push_back(root);
        }
      }
    }
    return ans;
  }

public:
  vector<TreeNode*> generateTrees(int n) {
    vector<int> nodesToAssign(n);
    for (int i = 1; i <= n; ++i)
      nodesToAssign[i - 1] = i;
    return go(nodesToAssign);
  }
};
