// 1701. Average Waiting Time
// https://leetcode.com/problems/average-waiting-time/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  double averageWaitingTime(vector<vector<int>>& customers) {
    double time = 0;
    int curr = 0;
    for (const vector<int>& customer : customers) {
      int start = max(customer[0], curr);
      int finish = start + customer[1];
      time += finish - customer[0];
      curr = finish;
    }
    return time / customers.size();
  }
};
