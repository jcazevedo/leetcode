// 109. Convert Sorted List to Binary Search Tree
// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

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

class Solution {
 private:
  TreeNode *go(ListNode *head, ListNode *until) {
    if (head == until) { return nullptr; }
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != until && fast->next != until) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return new TreeNode(slow->val, go(head, slow), go(slow->next, until));
  }

 public:
  TreeNode *sortedListToBST(ListNode *head) { return go(head, nullptr); }
};
