struct ListNode {
  int val;
  ListNode* next;

  ListNode() : val(0), next(nullptr) {}

  ListNode(int x) : val(x), next(nullptr) {}

  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  void reorderList(ListNode* head) {
    ListNode* prev = new ListNode();
    prev->next = head;
    ListNode* next = head;
    while (next != nullptr) {
      next = next->next;
      prev = prev->next;
    }
    head->next = prev;
  }
};
