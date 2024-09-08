// 1367. Linked List in Binary Tree
// https://leetcode.com/problems/linked-list-in-binary-tree/

#ifdef LOCAL
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif

class Solution {
 private:
  bool pathFrom(TreeNode *root, ListNode *curr) {
    if (curr == nullptr) { return true; }
    if (root == nullptr) { return false; }
    if (root->val != curr->val) { return false; }
    return pathFrom(root->left, curr->next) || pathFrom(root->right, curr->next);
  }

 public:
  bool isSubPath(ListNode *head, TreeNode *root) {
    if (root == nullptr) { return head == nullptr; }
    return pathFrom(root, head) || isSubPath(head, root->left) || isSubPath(head, root->right);
  }
};
