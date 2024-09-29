// 2807. Insert Greatest Common Divisors in Linked List
// https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/

#ifdef LOCAL
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
#endif

class Solution {
 private:
  int gcd(int a, int b) { return a == 0 ? b : gcd(b % a, a); }

 public:
  ListNode* insertGreatestCommonDivisors(ListNode* head) {
    ListNode* curr = head;
    while (curr->next != nullptr) {
      ListNode* gcdNode = new ListNode(gcd(curr->val, curr->next->val));
      gcdNode->next = curr->next;
      curr->next = gcdNode;
      curr = gcdNode->next;
    }
    return head;
  }
};
