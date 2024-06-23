// 147. Insertion Sort List
// https://leetcode.com/problems/insertion-sort-list/

struct ListNode {
  int val;
  ListNode* next;

  ListNode() : val(0), next(nullptr) {}

  ListNode(int x) : val(x), next(nullptr) {}

  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* insertionSortList(ListNode* head) {
    if (head == nullptr) return head;
    ListNode* sorted = new ListNode();
    sorted->next = head;
    ListNode* to_sort = head->next;
    sorted->next->next = nullptr;
    while (to_sort != nullptr) {
      ListNode* next_to_sort = to_sort->next;
      to_sort->next = nullptr;
      ListNode* prev = sorted;
      while (prev->next != nullptr && prev->next->val < to_sort->val) { prev = prev->next; }
      ListNode* after = prev->next;
      prev->next = to_sort;
      to_sort->next = after;
      to_sort = next_to_sort;
    }
    return sorted->next;
  }
};
