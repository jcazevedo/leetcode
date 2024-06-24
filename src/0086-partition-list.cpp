// 86. Partition List
// https://leetcode.com/problems/partition-list/

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* partition(ListNode* head, int x) {
    ListNode* leftHead = nullptr;
    ListNode* left = leftHead;
    ListNode* rightHead = nullptr;
    ListNode* right = rightHead;
    ListNode* curr = head;
    while (curr != nullptr) {
      if (curr->val < x) {
        if (leftHead == nullptr) {
          leftHead = left = curr;
        } else {
          left->next = curr;
          left = left->next;
        }
      } else {
        if (rightHead == nullptr) {
          rightHead = right = curr;
        } else {
          right->next = curr;
          right = right->next;
        }
      }
      curr = curr->next;
    }
    if (right != nullptr) { right->next = nullptr; }
    if (leftHead == nullptr) {
      return rightHead;
    } else {
      if (left != nullptr) { left->next = rightHead; }
      return leftHead;
    }
  }
};
