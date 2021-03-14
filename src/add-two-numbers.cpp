struct ListNode {
  int val;
  ListNode* next;

  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry = 0) {
    if (l1 == nullptr && l2 == nullptr && carry == 0)
      return nullptr;
    int d1 = 0;
    int d2 = 0;
    if (l1 != nullptr)
      d1 = l1->val;
    if (l2 != nullptr)
      d2 = l2->val;
    int res = d1 + d2 + carry;
    ListNode* l = new ListNode(res % 10);
    l->next = addTwoNumbers(l1 != nullptr ? l1->next : nullptr,
                            l2 != nullptr ? l2->next : nullptr, res / 10);
    return l;
  }
};
