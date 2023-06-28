// 234. Palindrome Linked List
// https://leetcode.com/problems/palindrome-linked-list/

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
private:
  ListNode* getHalfNode(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
    }
    return slow;
  }

  ListNode* reverseList(ListNode* head, ListNode* prev = nullptr) {
    if (head == nullptr)
      return head;
    ListNode* next = head->next;
    head->next = prev;
    if (next == nullptr)
      return head;
    return reverseList(next, head);
  }

public:
  bool isPalindrome(ListNode* head) {
    if (head == nullptr)
      return true;
    ListNode* half = getHalfNode(head);
    ListNode* reverseHalf = reverseList(half->next);
    ListNode *i = head, *j = reverseHalf;
    bool ans = true;
    while (ans && j != nullptr) {
      if (i->val != j->val)
        ans = false;
      i = i->next;
      j = j->next;
    }
    half->next = reverseList(reverseHalf);
    return ans;
  }
};
