// 160. Intersection of Two Linked Lists
// https://leetcode.com/problems/intersection-of-two-linked-lists/

struct ListNode {
  int val;
  ListNode* next;

  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if (headA == nullptr || headB == nullptr) return nullptr;
    ListNode* a = headA;
    ListNode* b = headB;
    while (a != b) {
      a = (a == nullptr ? headB : a->next);
      b = (b == nullptr ? headA : b->next);
    }
    return a;
  }
};
