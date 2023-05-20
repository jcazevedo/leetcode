struct ListNode {
  int val;
  ListNode* next;

  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
private:
  void aux(ListNode* odd, ListNode* even, ListNode* current, int i, ListNode* evenHead) {
    if (current == nullptr) {
      odd->next = evenHead;
    } else if (i % 2 == 0) {
      odd->next = current;
      ListNode* ncurrent = current->next;
      current->next = nullptr;
      aux(odd->next, even, ncurrent, i + 1, evenHead);
    } else {
      even->next = current;
      ListNode* ncurrent = current->next;
      current->next = nullptr;
      aux(odd, even->next, ncurrent, i + 1, evenHead);
    }
  }

public:
  ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
      return head;
    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* current = head->next->next;
    head->next->next = nullptr;
    head->next = nullptr;
    aux(odd, even, current, 2, even);
    return head;
  }
};
