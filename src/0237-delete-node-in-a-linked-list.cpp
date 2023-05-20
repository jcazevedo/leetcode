// 237. Delete Node in a Linked List
// https://leetcode.com/problems/delete-node-in-a-linked-list/

struct ListNode {
  int val;
  ListNode* next;

  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  void deleteNode(ListNode* node) {
    ListNode* prev = new ListNode(0);
    ListNode* curr = node;
    prev->next = curr;
    while (curr->next != nullptr) {
      if (curr->next != nullptr)
        curr->val = curr->next->val;
      curr = curr->next;
      prev = prev->next;
    }
    prev->next = nullptr;
  }
};
