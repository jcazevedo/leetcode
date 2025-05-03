// 2071. Maximum Number of Tasks You Can Assign
// https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/

#include <algorithm>
#include <set>
#include <vector>

using namespace std;

class Solution {
 private:
  bool good(const vector<int>& tasks, const vector<int>& workers, int pills, int strength, int n_tasks) {
    multiset<int> valid_workers;
    int w = workers.size();
    for (int i = w - n_tasks; i < w; ++i) { valid_workers.insert(workers[i]); }
    for (int ti = n_tasks - 1; ti >= 0; --ti) {
      multiset<int>::iterator itr = prev(valid_workers.end());
      if (*itr >= tasks[ti]) {
        valid_workers.erase(itr);
      } else {
        if (pills == 0) { return false; }
        multiset<int>::iterator itr = valid_workers.lower_bound(tasks[ti] - strength);
        if (itr == valid_workers.end()) { return false; }
        --pills;
        valid_workers.erase(itr);
      }
    }
    return true;
  }

 public:
  int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
    int t = tasks.size(), w = workers.size();
    sort(tasks.begin(), tasks.end());
    sort(workers.begin(), workers.end());
    int lo = 0, hi = min(t, w);
    while (lo < hi) {
      int mid = lo + (hi - lo + 1) / 2;
      if (good(tasks, workers, pills, strength, mid)) {
        lo = mid;
      } else {
        hi = mid - 1;
      }
    }
    return lo;
  }
};
