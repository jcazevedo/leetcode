struct ListNode {
  int val;
  ListNode* next;

  ListNode() : val(0), next(nullptr) {}

  ListNode(int x) : val(x), next(nullptr) {}

  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr) return head;
    int len = 1;
    ListNode* curr = head;
    while (curr->next != nullptr) {
      curr = curr->next;
      len++;
    }
    curr->next = head;
    k = len - k % len;
    while (k-- > 0) {
      curr = curr->next;
    }
    ListNode* ans = curr->next;
    curr->next = nullptr;
    return ans;
  }
};
