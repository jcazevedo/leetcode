// 21. Merge Two Sorted Lists
// https://leetcode.com/problems/merge-two-sorted-lists/

struct ListNode {
  int val;
  ListNode* next;

  ListNode() : val(0), next(nullptr) {}

  ListNode(int x) : val(x), next(nullptr) {}

  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode();
    ListNode* curr = head;
    while (l1 != nullptr || l2 != nullptr) {
      if (l1 == nullptr) {
        curr->next = l2;
        curr = l2;
        l2 = l2->next;
      } else if (l2 == nullptr) {
        curr->next = l1;
        curr = l1;
        l1 = l1->next;
      } else if (l1->val < l2->val) {
        curr->next = l1;
        curr = l1;
        l1 = l1->next;
      } else {
        curr->next = l2;
        curr = l2;
        l2 = l2->next;
      }
    }
    return head->next;
  }
};
