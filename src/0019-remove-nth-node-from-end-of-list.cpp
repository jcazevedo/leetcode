// 19. Remove Nth Node From End of List
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

struct ListNode {
  int val;
  ListNode* next;

  ListNode() : val(0), next(nullptr) {}

  ListNode(int x) : val(x), next(nullptr) {}

  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* new_head = new ListNode(0, head);
    ListNode* first = new_head;
    ListNode* second = new_head;
    for (int i = 0; i <= n; ++i) {
      second = second->next;
    }
    while (second != nullptr) {
      first = first->next;
      second = second->next;
    }
    first->next = first->next->next;
    return new_head->next;
  }
};
