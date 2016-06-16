/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry = 0) {
    if (l1 == NULL && l2 == NULL && carry == 0)
      return NULL;
    int d1 = 0;
    int d2 = 0;
    if (l1 != NULL)
      d1 = l1->val;
    if (l2 != NULL)
      d2 = l2->val;
    int res = d1 + d2 + carry;
    ListNode * l = new ListNode(res % 10);
    l->next = addTwoNumbers(l1 != NULL ? l1->next : NULL, l2 != NULL ? l2->next : NULL, res / 10);
    return l;
  }
};
