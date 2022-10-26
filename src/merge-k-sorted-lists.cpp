#include <queue>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;

  ListNode() : val(0), next(nullptr) {}

  ListNode(int x) : val(x), next(nullptr) {}

  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* head = new ListNode();
    ListNode* curr = head;
    priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
    for (ListNode* list : lists) {
      if (list != nullptr) pq.emplace(list->val, list);
    }
    while (!pq.empty()) {
      ListNode* next = pq.top().second;
      pq.pop();
      curr->next = next;
      curr = next;
      next = next->next;
      if (next != nullptr) pq.emplace(next->val, next);
    }
    return head->next;
  }
};
