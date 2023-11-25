// 295. Find Median from Data Stream
// https://leetcode.com/problems/find-median-from-data-stream/

#include <queue>
#include <vector>

using namespace std;

class MedianFinder {
 private:
  priority_queue<int> pq_left;
  priority_queue<int, vector<int>, greater<int>> pq_right;

 public:
  MedianFinder() {}

  void addNum(int num) {
    if (!pq_left.empty() && num > pq_left.top()) {
      pq_right.push(num);
      if (pq_right.size() > pq_left.size() + 1) {
        pq_left.push(pq_right.top());
        pq_right.pop();
      }
    } else {
      pq_left.push(num);
      if (pq_left.size() > pq_right.size() + 1) {
        pq_right.push(pq_left.top());
        pq_left.pop();
      }
    }
  }

  double findMedian() {
    if (pq_left.size() == pq_right.size())
      return (pq_left.top() + pq_right.top()) / 2.0;
    if (pq_right.size() > pq_left.size()) return pq_right.top();
    return pq_left.top();
  }
};
