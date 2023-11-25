// 25. Reverse Nodes in k-Group
// https://leetcode.com/problems/reverse-nodes-in-k-group/

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == nullptr) return head;
    ListNode *curr = head, *next = nullptr, *prev = nullptr;
    int count = 0;
    while (curr != nullptr && count < k) {
      curr = curr->next;
      ++count;
    }
    if (count != k) return head;
    count = 0;
    curr = head;
    while (curr != nullptr && count < k) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
      ++count;
    }
    if (next != nullptr) head->next = reverseKGroup(next, k);
    return prev;
  }
};
