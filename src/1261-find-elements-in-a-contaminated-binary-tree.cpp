// 1261. Find Elements in a Contaminated Binary Tree
// https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/

#include <unordered_set>

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

class FindElements {
 private:
  unordered_set<int> elems;

  void recover(TreeNode *curr, int value = 0) {
    if (curr == nullptr) { return; }
    elems.insert(value);
    curr->val = value;
    recover(curr->left, value * 2 + 1);
    recover(curr->right, value * 2 + 2);
  }

 public:
  FindElements(TreeNode *root) { recover(root); }

  bool find(int target) { return elems.count(target); }
};
