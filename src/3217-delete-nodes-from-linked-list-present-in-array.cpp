// 3217. Delete Nodes From Linked List Present in Array
// https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/

#include <unordered_set>
#include <vector>

using namespace std;

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
 public:
  ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    unordered_set<int> numSet;
    for (int num : nums) { numSet.insert(num); }
    ListNode* tempHead = new ListNode(-1, head);
    ListNode* curr = tempHead;
    while (curr->next != nullptr) {
      if (numSet.find(curr->next->val) != numSet.end()) {
        curr->next = curr->next->next;
      } else {
        curr = curr->next;
      }
    }
    return tempHead->next;
  }
};
