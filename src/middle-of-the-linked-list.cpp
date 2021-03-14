struct ListNode {
  int val;
  ListNode* next;

  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next;
      if (fast->next != nullptr) { fast = fast->next; }
    }
    return slow;
  }
};
