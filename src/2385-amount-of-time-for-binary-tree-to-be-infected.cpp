// 2385. Amount of Time for Binary Tree to Be Infected
// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/

#include <algorithm>
#include <unordered_map>

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
  void fillParentsAndGetStart(TreeNode* curr,
                              int start,
                              TreeNode* prev,
                              unordered_map<TreeNode*, TreeNode*>& parent,
                              TreeNode*& startNode) {
    if (curr == nullptr) return;
    if (prev != nullptr) parent[curr] = prev;
    if (curr->val == start) startNode = curr;
    fillParentsAndGetStart(curr->left, start, curr, parent, startNode);
    fillParentsAndGetStart(curr->right, start, curr, parent, startNode);
  }

  int infect(TreeNode* curr,
             unordered_map<TreeNode*, TreeNode*>& parent,
             TreeNode* prev) {
    int ans = 0;

    if (parent[curr] != nullptr && parent[curr] != prev)
      ans = max(ans, infect(parent[curr], parent, curr) + 1);

    if (curr->left != nullptr && curr->left != prev)
      ans = max(ans, infect(curr->left, parent, curr) + 1);

    if (curr->right != nullptr && curr->right != prev)
      ans = max(ans, infect(curr->right, parent, curr) + 1);

    return ans;
  }

 public:
  int amountOfTime(TreeNode* root, int start) {
    TreeNode* startNode = nullptr;
    unordered_map<TreeNode*, TreeNode*> parent;
    fillParentsAndGetStart(root, start, nullptr, parent, startNode);

    return infect(startNode, parent, nullptr);
  }
};
