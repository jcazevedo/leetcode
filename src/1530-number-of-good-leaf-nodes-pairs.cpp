// 1530. Number of Good Leaf Nodes Pairs
// https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/

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
  vector<int> dfs(TreeNode *root, int distance, int &ans) {
    if (root == nullptr) { return vector<int>(); }
    if (root->left == nullptr && root->right == nullptr) { return {0}; }
    vector<int> left = dfs(root->left, distance, ans);
    vector<int> right = dfs(root->right, distance, ans);
    for (int l : left) {
      for (int r : right) {
        if (l + r + 2 <= distance) { ++ans; }
      }
    }
    vector<int> res;
    for (int l : left) { res.push_back(l + 1); }
    for (int r : right) { res.push_back(r + 1); }
    return res;
  }

 public:
  int countPairs(TreeNode *root, int distance) {
    int ans = 0;
    dfs(root, distance, ans);
    return ans;
  }
};
