// 725. Split Linked List in Parts
// https://leetcode.com/problems/split-linked-list-in-parts/

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
  vector<ListNode*> splitListToParts(ListNode* head, int k) {
    int len = 0;
    ListNode* curr = head;
    while (curr != nullptr) {
      ++len;
      curr = curr->next;
    }
    int size = len / k, rem = len % k;
    vector<ListNode*> ans;
    int currLen = 0;
    while (head != nullptr) {
      ListNode* prev = head;
      head = head->next;
      if (currLen == 0) ans.push_back(prev);

      currLen++;
      if ((rem > 0 && currLen == size + 1) || (rem == 0 && currLen == size)) {
        prev->next = nullptr;
        if (rem > 0) { --rem; }
        currLen = 0;
      }
    }
    while ((int)ans.size() < k) { ans.push_back(nullptr); }
    return ans;
  }
};
