// 142. Linked List Cycle II
// https://leetcode.com/problems/linked-list-cycle-ii/

#ifdef LOCAL
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};
#endif

class Solution {
 public:
  ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        ListNode* start = head;
        while (start != slow) {
          start = start->next;
          slow = slow->next;
        }
        return start;
      }
    }
    return nullptr;
  }
};
