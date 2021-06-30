struct ListNode {
  int val;
  ListNode *next;

  ListNode() : val(0), next(nullptr) {}

  ListNode(int x) : val(x), next(nullptr) {}

  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
  ListNode *merge_sorted(ListNode *left, ListNode *right) {
    ListNode fake = ListNode();
    ListNode *curr = &fake;
    while (left != nullptr && right != nullptr) {
      if (left->val < right->val) {
        curr->next = left;
        left = left->next;
      } else {
        curr->next = right;
        right = right->next;
      }
      curr = curr->next;
    }
    curr->next = left != nullptr ? left : right;
    return fake.next;
  }

  ListNode *merge_sort(ListNode *head) {
    if (head == nullptr)
      return head;
    if (head->next == nullptr)
      return head;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode *left = head;
    ListNode *right = slow->next;
    slow->next = nullptr;
    ListNode *left_sorted = merge_sort(left);
    ListNode *right_sorted = merge_sort(right);
    return merge_sorted(left_sorted, right_sorted);
  }

public:
  ListNode *sortList(ListNode *head) { return merge_sort(head); }
};
