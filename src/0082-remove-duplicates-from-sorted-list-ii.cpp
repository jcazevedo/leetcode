// 82. Remove Duplicates from Sorted List II
// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr) return head;
    ListNode* parent = new ListNode(-1);
    parent->next = head;
    ListNode* pre = parent;
    ListNode* curr = head;
    while (curr != nullptr) {
      while (curr->next != nullptr && curr->val == curr->next->val)
        curr = curr->next;
      if (pre->next == curr)
        pre = pre->next;
      else
        pre->next = curr->next;
      curr = curr->next;
    }
    return parent->next;
  }
};
