struct ListNode {
  int val;
  ListNode *next;

  ListNode() : val(0), next(nullptr) {}

  ListNode(int x) : val(x), next(nullptr) {}

  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  int getDecimalValue(ListNode *head, int current = 0) {
    if (head == nullptr)
      return current;
    int next_current = current * 2 + head->val;
    return getDecimalValue(head->next, next_current);
  }
};
