// 83. Remove Duplicates from Sorted List
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
    ListNode *curr = head, *prev = nullptr;
    while (curr != nullptr) {
      if (prev != nullptr && curr->val == prev->val)
        prev->next = curr->next;
      else
        prev = curr;
      curr = curr->next;
    }
    return head;
  }
};
