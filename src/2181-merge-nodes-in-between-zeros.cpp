// 2181. Merge Nodes in Between Zeros
// https://leetcode.com/problems/merge-nodes-in-between-zeros/

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* mergeNodes(ListNode* head) {
    ListNode* curr = head;
    while (true) {
      if (curr->next->val == 0) {
        if (curr->next->next == nullptr) {
          curr->next = nullptr;
          break;
        } else {
          curr = curr->next;
        }
      } else {
        curr->val += curr->next->val;
        curr->next = curr->next->next;
      }
    }
    return head;
  }
};
