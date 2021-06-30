#include <cstdlib>
#include <ctime>

struct ListNode {
  int val;
  ListNode *next;

  ListNode() : val(0), next(nullptr) {}

  ListNode(int x) : val(x), next(nullptr) {}

  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
  ListNode *list;

public:
  Solution(ListNode *head) {
    list = head;
    srand(time(NULL));
  }

  int getRandom() {
    double n = 1.0, k = 1.0;
    ListNode *head = list, *ans = list;
    while (head->next) {
      n += 1.0;
      head = head->next;
      if (((double)rand() / RAND_MAX) < k / n) {
        ans = ans->next;
        k += 1.0;
      }
    }
    return ans->val;
  }
};
