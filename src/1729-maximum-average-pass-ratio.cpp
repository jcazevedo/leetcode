// 1792. Maximum Average Pass Ratio
// https://leetcode.com/problems/maximum-average-pass-ratio/

#include <queue>
#include <vector>

using namespace std;

struct PassRate {
  double nextRate;
  int pass;
  int total;

  bool operator<(const PassRate& rhs) const { return nextRate < rhs.nextRate; }
};

class Solution {
 private:
  double nextRate(int pass, int total) { return (pass + 1.0) / (total + 1.0) - ((double)pass) / total; }

 public:
  double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
    priority_queue<PassRate> pq;
    for (vector<int>& cls : classes) { pq.push({nextRate(cls[0], cls[1]), cls[0], cls[1]}); }
    while (extraStudents--) {
      PassRate best = pq.top();
      pq.pop();
      pq.push({nextRate(best.pass + 1, best.total + 1), best.pass + 1, best.total + 1});
    }
    double ans = 0.0;
    while (!pq.empty()) {
      PassRate curr = pq.top();
      pq.pop();
      ans += ((double)curr.pass) / curr.total;
    }
    ans /= classes.size();
    return ans;
  }
};
